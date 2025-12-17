#include <stdio.h>
#include "funzioni.h"

int main(void) {
    Inp in;
    if (!leggi("input.txt", &in)) {
        printf("Errore input.\n");
        return 1;
    }
    cerca(&in);
    return 0;
}