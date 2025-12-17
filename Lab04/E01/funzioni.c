#include <stdio.h>
#include "funzioni.h"

static int sol[ MAXN ];
static int best[ MAXN ];
static int n;

static int ok_cover(const Grafo *g) {
    for (int i = 0; i < g->e; i++) {
        int a = g->u[i], b = g->v[i];
        if (!sol[a] && !sol[b]) return 0;
    }
    return 1;
}

static void rec(const Grafo *g, int pos) {
    if (pos == g->n) {
        if (ok_cover(g)) {
            printf("{ ");
            for (int i = 0; i < g->n; i++)
                if (sol[i]) printf("%d ", i);
            printf("}\n");
        }
        return;
    }

    sol[pos] = 0;
    rec(g, pos + 1);

    sol[pos] = 1;
    rec(g, pos + 1);
}

int leggi_grafo(const char *f, Grafo *g) {
    FILE *fp = fopen(f, "r");
    if (!fp) return 0;
    fscanf(fp, "%d %d", &g->n, &g->e);
    for (int i = 0; i < g->e; i++)
        fscanf(fp, "%d %d", &g->u[i], &g->v[i]);
    fclose(fp);
    return 1;
}

void vertex_cover(const Grafo *g) {
    rec(g, 0);
}