#ifndef INV_H
#define INV_H

typedef struct {
    char nome[50];
    char tipo[50];
    int mod[6];
} ogg_t;

typedef struct {
    ogg_t *v;
    int n;
} inv_t;

int invLoad(inv_t *inv, char *nome);
int invFind(inv_t *inv, char *nome);

void invPrintOne(inv_t *inv, int i);

#endif