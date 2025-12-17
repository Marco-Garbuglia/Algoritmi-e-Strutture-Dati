#ifndef PG_H
#define PG_H

#include "inventario.h"

typedef struct nodo_pg *link;

typedef struct {
    char codice[10];
    char nome[50];
    char classe[50];
    int base[6];
    int eq[8];
} pg_t;

struct nodo_pg {
    pg_t pg;
    link next;
};

typedef struct {
    link h;
} lista_pg;

void pgListInit(lista_pg *L);
void pgListLoad(lista_pg *L, char *nome);

link pgFind(lista_pg *L, char *cod);
void pgAdd(lista_pg *L, pg_t x);
void pgDel(lista_pg *L, char *cod);

void pgEquipAdd(pg_t *pg, int idx);
void pgEquipDel(pg_t *pg, int idx);

void pgPrint(pg_t *pg, inv_t *inv);

#endif