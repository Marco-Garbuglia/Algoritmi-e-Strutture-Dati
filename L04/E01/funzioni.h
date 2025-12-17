#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAXN 40
#define MAXE 200

typedef struct {
    int n, e;
    int u[MAXE];
    int v[MAXE];
} Grafo;

int leggi_grafo(const char *f, Grafo *g);
void vertex_cover(const Grafo *g);

#endif