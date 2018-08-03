#include <stdio.h>

int main(void) {
    const int a = 42; // Konstante
    int b; // Integer Variable
    b = a; // Zuweisung (Englisch: Assignment)
    //a = b; // Fehler beim Kompilieren
    b = 2 * a; // Ausdruck (Englisch: Expression)
    printf("%d\n", b); // Integer ausgeben
    return 0;
}
