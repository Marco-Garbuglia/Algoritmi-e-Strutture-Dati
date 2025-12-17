#include <stdio.h>
#include "funzioni.h"

int main(void) {
    Play p;
    if (!leggi("brani.txt", &p)) {
        printf("Errore input.\n");
        return 1;
    }

    genera(&p);
    return 0;
}