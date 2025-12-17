#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personaggi.h"

void pgListInit(lista_pg *L) {
    L->h = NULL;
}

void pgListLoad(lista_pg *L, char *nome) {
    FILE *fp = fopen(nome, "r");
    int i;
    pg_t tmp;

    if (!fp) return;

    while (fscanf(fp, "%s %s %s %d %d %d %d %d %d",
                  tmp.codice, tmp.nome, tmp.classe,
                  &tmp.base[0], &tmp.base[1], &tmp.base[2],
                  &tmp.base[3], &tmp.base[4], &tmp.base[5]) == 9) {

        for (i = 0; i < 8; i++) tmp.eq[i] = -1;
        pgAdd(L, tmp);
    }

    fclose(fp);
}

link pgFind(lista_pg *L, char *cod) {
    link x = L->h;
    while (x) {
        if (!strcmp(x->pg.codice, cod))
            return x;
        x = x->next;
    }
    return NULL;
}

void pgAdd(lista_pg *L, pg_t x) {
    link t = malloc(sizeof(*t));
    t->pg = x;
    t->next = L->h;
    L->h = t;
}

void pgDel(lista_pg *L, char *cod) {
    link x = L->h, p = NULL;

    while (x) {
        if (!strcmp(x->pg.codice, cod)) {
            if (p) p->next = x->next;
            else L->h = x->next;
            free(x);
            return;
        }
        p = x;
        x = x->next;
    }
}

void pgEquipAdd(pg_t *pg, int idx) {
    int i;
    for (i = 0; i < 8; i++)
        if (pg->eq[i] == -1) {
            pg->eq[i] = idx;
            return;
        }
}

void pgEquipDel(pg_t *pg, int idx) {
    int i;
    for (i = 0; i < 8; i++)
        if (pg->eq[i] == idx)
            pg->eq[i] = -1;
}

void pgPrint(pg_t *pg, inv_t *inv) {
    int i, r[6];
    for (i = 0; i < 6; i++)
        r[i] = pg->base[i];

    for (i = 0; i < 8; i++) {
        int k = pg->eq[i];
        if (k != -1) {
            int j;
            for (j = 0; j < 6; j++)
                r[j] += inv->v[k].mod[j];
        }
    }

    for (i = 0; i < 6; i++)
        if (r[i] < 0) r[i] = 0;

    printf("%s %s %s\n", pg->codice, pg->nome, pg->classe);
    for (i = 0; i < 6; i++) printf("%d ", r[i]);
    printf("\n");
}