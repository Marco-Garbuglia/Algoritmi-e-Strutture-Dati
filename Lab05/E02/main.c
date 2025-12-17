#include <stdio.h>
#include "funzioni.h"

tile t[200];
int b[30][30], r[30][30];

int main() {
    int nt, R, C;
    int temp_rot;

    if (scanf("%d", &nt) != 1) return 1;
    for (int i = 0; i < nt; i++)
        if (scanf("%d %d %d %d", &t[i].a, &t[i].b, &t[i].c, &t[i].d) != 4) return 1;

    if (scanf("%d %d", &R, &C) != 2) return 1;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (scanf("%d/%d", &b[i][j], &temp_rot) != 2) return 1;
            r[i][j] = temp_rot;
        }
    }

    solve(t, nt, b, r, R, C);
    return 0;
}