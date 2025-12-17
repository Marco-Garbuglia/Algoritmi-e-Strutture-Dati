#ifndef FUNZIONI_H
#define FUNZIONI_H

typedef struct {
    int a, b, c, d;
} tile;

void solve(tile t[], int nt, int b[][30], int r[][30], int R, int C);

#endif