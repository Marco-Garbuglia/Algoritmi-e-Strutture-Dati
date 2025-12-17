#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personaggi.h"
#include "inventario.h"

int main() {
    lista_pg L;
    inv_t inv;
    char cod[10], nomeOgg[50];
    int idx;

    pgListInit(&L);
    pgListLoad(&L, "pg.txt");
    invLoad(&inv, "inventario.txt");

    int cmd = -1;
    while (cmd != 0) {
        printf("1 stampa\n2 aggiungi\n3 elimina\n4 add ogg\n5 del ogg\n0 esci\n> ");
        scanf("%d", &cmd);

        if (cmd == 1) {
            link x = L.h;
            while (x) {
                pgPrint(&x->pg, &inv);
                x = x->next;
            }
        }

        else if (cmd == 2) {
            pg_t tmp;
            int i;
            printf("cod nome classe stats...\n");
            scanf("%s %s %s %d %d %d %d %d %d",
                  tmp.codice, tmp.nome, tmp.classe,
                  &tmp.base[0], &tmp.base[1], &tmp.base[2],
                  &tmp.base[3], &tmp.base[4], &tmp.base[5]);
            for (i = 0; i < 8; i++) tmp.eq[i] = -1;
            pgAdd(&L, tmp);
        }

        else if (cmd == 3) {
            printf("codice: ");
            scanf("%s", cod);
            pgDel(&L, cod);
        }

        else if (cmd == 4) {
            printf("codice pg: ");
            scanf("%s", cod);
            link x = pgFind(&L, cod);
            if (x) {
                printf("nome oggetto: ");
                scanf("%s", nomeOgg);
                idx = invFind(&inv, nomeOgg);
                if (idx >= 0) pgEquipAdd(&x->pg, idx);
            }
        }

        else if (cmd == 5) {
            printf("codice pg: ");
            scanf("%s", cod);
            link x = pgFind(&L, cod);
            if (x) {
                printf("nome oggetto: ");
                scanf("%s", nomeOgg);
                idx = invFind(&inv, nomeOgg);
                if (idx >= 0) pgEquipDel(&x->pg, idx);
            }
        }
    }

    return 0;
}