// http://heather.cs.ucdavis.edu/~matloff/UnixAndC/CLanguage/Curses.pdf

// psax.c; illustration of curses library

// runs the shell command 'ps ax' and dislays the last lines of its output,
// as many as the window will fit; allows the user to move up and down
// within the window, with the option to kill whichever process is 
// currently highlighted

// usage:  psax

// user commands:

//    'u':  move highlight up a line
//    'd':  move highlight down a line
//    'k':  kill process in currently highlighted line
//    'r':  re-run 'ps ax' for update
//    'q':  quit

// possible extensions:  allowing scrolling, so that the user could go
// through all the 'ps ax' output, not just the last lines; allow
// wraparound for long lines; ask user to confirm before killing a
// process

#define MAXROW 1000
#define MAXCOL 500

#include <curses.h>  // required

WINDOW *scrn; // will point to curses window object

char cmdoutlines[MAXROW][MAXCOL];  // output of 'ps ax' (better to use
                                   // malloc())
int ncmdlines,  // number of rows in cmdoutlines
    nwinlines,  // number of rows our "ps ax" output occupies in the 
                //  xterm (or equiv.) window 
    winrow,  // current row position in screen
    cmdstartrow,  // index of first row in cmdoutlines to be displayed
    cmdlastrow;  // index of last row in cmdoutlines to be displayed

// rewrites the line at winrow in bold font
void highlight() {
   int clinenum;
   attron(A_BOLD);  // this curses library call says that whatever we 
                    // write from now on (until we say otherwise) 
                    // will be in bold font 
   // we'll need to rewrite the cmdoutlines line currently displayed
   // at line winrow in the screen, so as to get the bold font
   clinenum = cmdstartrow + winrow;
   mvaddstr(winrow,0,cmdoutlines[clinenum]);
   attroff(A_BOLD);  // OK, leave bold mode
   refresh();  // make the change appear on the screen
}

// runs "ps ax" and stores the output in cmdoutlines
void runpsax() {
   FILE *p; char ln[MAXCOL]; int row,tmp;
   p = popen("ps ax","r");  // open Unix pipe (enables one program to read
                            // output of another as if it were a file)
   for (row = 0; row < MAXROW; row++)  {
      tmp = fgets(ln,MAXCOL,p);  // read one line from the pipe
      if (tmp == NULL) break;  // if end of pipe, break
      // don't want stored line to exceed width of screen, which the
      // curses library provides to us in the variable COLS, so truncate
      // to at most COLS characters
      strncpy(cmdoutlines[row],ln,COLS);
      // remove EOL character
      cmdoutlines[row][MAXCOL-1] = 0;
   }
   ncmdlines = row;
   close(p);  // close pipe
}

// displays last part of command output (as much as fits in screen)
void showlastpart() {  int row;
   clear();  // curses clear-screen call
   // prepare to paint the (last part of the) 'ps ax' output on the screen
   // two cases, depending on whether there is more output than screen rows;
   // first, the case in which the entire output fits in one screen:
   if (ncmdlines <= LINES)  { // LINES is an int maintained by the curses
                              // library, equal to the number of lines in
                              // the screen
      cmdstartrow = 0;
      nwinlines = ncmdlines;
   }
   else  { // now the case in which the output is bigger than one screen
      cmdstartrow = ncmdlines - LINES;
      nwinlines = LINES;
   }
   cmdlastrow = cmdstartrow + nwinlines - 1;
   // now paint the rows to the screen
   for (row = cmdstartrow, winrow = 0; row <= cmdlastrow; row++,winrow++)  
      mvaddstr(winrow,0,cmdoutlines[row]);  // curses call to move to the
                                            // specified position and
                                            // paint a string there
   refresh();  // now make the changes actually appear on the screen,
               // using this call to the curses library
   // highlight the last line
   winrow--;  
   highlight();
}

// moves up/down one line
void updown(int inc)
{  int tmp = winrow + inc; 
   // ignore attempts to go off the edge of the screen
   if (tmp >= 0 && tmp < LINES)  {
      // rewrite the current line before moving; since our current font
      // is non-BOLD (actually A_NORMAL), the effect is to unhighlight
      // this line
      mvaddstr(winrow,0,cmdoutlines[cmdstartrow+winrow]);
      // highlight the line we're moving to
      winrow = tmp;
      highlight();
   }
}

// run/re-run "ps ax"
void rerun() {  
   runpsax();
   showlastpart();
}

// kills the highlighted process
void prockill() {  
   char *pid;
   // strtok() is from C library; see man page
   pid = strtok(cmdoutlines[cmdstartrow+winrow]," ");
   kill(atoi(pid),9);  // this is a Unix system call to send signal 9, 
                       // the kill signal, to the given process
   rerun();
}

int main(void) {  
   char c;
   // window setup, next 3 lines are curses library calls, a standard
   // initializing sequence for curses programs
   scrn = initscr();
   noecho();  // don't echo keystrokes
   cbreak();  // keyboard input valid immediately, not after hit Enter
   // run 'ps ax' and process the output
   runpsax();
   // display in the window
   showlastpart();
   // user command loop
   while (1)  {
      // get user command
      c = getch();
      if (c == 'u') updown(-1);
      else if (c == 'd') updown(1);
      else if (c == 'r') rerun();
      else if (c == 'k') prockill();
      else break;  // quit
   }
   // restore original settings and leave
   endwin();
}
