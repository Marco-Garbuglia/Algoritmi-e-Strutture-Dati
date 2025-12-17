#include <stdio.h>
#include "funzioni.h"

int main(void) {
    Grafo g;

    if (!leggi_grafo("input.txt", &g)) {
        printf("Errore lettura input.\n");
        return 1;
    }

    vertex_cover(&g);
    return 0;
}