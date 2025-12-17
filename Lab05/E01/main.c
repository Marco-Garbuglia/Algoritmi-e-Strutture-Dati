#include <stdio.h>
#include "funzioni.h"

int main() {
    att v[200];
    int n = leggi(v, 200);

    if (n == 0) {
        printf("Nessuna attivita' letta.\n");
        return 1;
    }

    attSel(n, v);
    return 0;
}