// quine - a program that prints itself, code is a format string, 10 is newline, 34 is double quote
#include <stdio.h>

int main() {
    char code[] = "// quine - a program that prints itself, code is a format string, 10 is newline, 34 is double quote%c#include <stdio.h>%c%cint main() {%c    char code[] = %c%s%c;%c    printf(code, 10, 10, 10, 10, 34, code, 34, 10, 10, 10);%c}%c";
    printf(code, 10, 10, 10, 10, 34, code, 34, 10, 10, 10);
}
