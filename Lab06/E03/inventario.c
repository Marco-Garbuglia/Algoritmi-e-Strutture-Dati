#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"

int invLoad(inv_t *inv, char *nome) {
    FILE *fp = fopen(nome, "r");
    int i;

    if (!fp) return 0;

    fscanf(fp, "%d", &inv->n);
    inv->v = malloc(inv->n * sizeof(ogg_t));

    for (i = 0; i < inv->n; i++) {
        fscanf(fp, "%s %s %d %d %d %d %d %d",
               inv->v[i].nome,
               inv->v[i].tipo,
               &inv->v[i].mod[0],
               &inv->v[i].mod[1],
               &inv->v[i].mod[2],
               &inv->v[i].mod[3],
               &inv->v[i].mod[4],
               &inv->v[i].mod[5]);
    }

    fclose(fp);
    return 1;
}

int invFind(inv_t *inv, char *nome) {
    int i;
    for (i = 0; i < inv->n; i++)
        if (!strcmp(inv->v[i].nome, nome))
            return i;
    return -1;
}

void invPrintOne(inv_t *inv, int i) {
    int k;
    printf("%s %s ", inv->v[i].nome, inv->v[i].tipo);
    for (k = 0; k < 6; k++)
        printf("%d ", inv->v[i].mod[k]);
    printf("\n");
}