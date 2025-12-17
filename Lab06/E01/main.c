#include <stdio.h>
#include <stdlib.h>
#include "att.h"

int main() {
    att_t *v;
    int n, k, *sol;

    v = leggiAtt("att.txt", &n);
    if (!v) {
        printf("Errore file.\n");
        return 1;
    }

    sol = malloc(n * sizeof(int));
    for (k = 0; k < n; k++) sol[k] = -1;

    int max = solveDP(v, n, sol);

    printf("Massimo numero attività: %d\n", max);
    stampaSol(v, sol, max);

    free(sol);
    free(v);
    return 0;
}