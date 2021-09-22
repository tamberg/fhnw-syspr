# include <stdio.h>

int main(void) {
    //char s[] = "hey"; //{'h', 'o', 'i', '\0'};
    char *s = "hoi";
    for (char *p = s; *p != '\0'; p++) {
        printf("%c", *p);
    }
    printf("\n%s", s);
    return 0;
}
