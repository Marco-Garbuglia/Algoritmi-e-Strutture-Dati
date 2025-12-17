#ifndef FUNZIONI_H
#define FUNZIONI_H

typedef struct {
    int z, r, t, s;
} Inp;

int leggi(const char *f, Inp *in);
void cerca(const Inp *in);

#endif