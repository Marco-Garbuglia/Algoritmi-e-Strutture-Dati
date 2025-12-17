#include <stdio.h>
#include <string.h>
#include "funzioni.h"

static char sol[ MAXA ][ MAXLEN ];
static int A;

static void rec(const Play *p, int i) {
    if (i == p->A) {
        for (int k = 0; k < p->A; k++)
            printf("%s ", sol[k]);
        printf("\n");
        return;
    }

    for (int j = 0; j < p->C[i]; j++) {
        strcpy(sol[i], p->brani[i][j]);
        rec(p, i + 1);
    }
}

int leggi(const char *f, Play *p) {
    FILE *fp = fopen(f, "r");
    if (!fp) return 0;

    fscanf(fp, "%d", &p->A);

    for (int i = 0; i < p->A; i++) {
        fscanf(fp, "%d", &p->C[i]);
        for (int j = 0; j < p->C[i]; j++)
            fscanf(fp, "%s", p->brani[i][j]);
    }

    fclose(fp);
    return 1;
}

void genera(const Play *p) {
    rec(p, 0);
}