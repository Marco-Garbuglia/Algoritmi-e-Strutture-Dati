#include <stdio.h>
#include <string.h>
#include "funzioni.h"

static char sol[20000];
static char best[20000];
static int lc, lb;

static int ok(char a, char b) {
    if (a=='Z') return (b=='Z'||b=='R');
    if (a=='R') return (b=='S'||b=='T');
    if (a=='T') return (b=='Z'||b=='R');
    if (a=='S') return (b=='S'||b=='T');
    return 1;
}

static void bt(int z,int r,int t,int s) {
    if (lc > lb) {
        lb = lc;
        memcpy(best, sol, lc);
        best[lc] = 0;
    }

    struct { char c; int *q; } v[4] = {
        {'Z', &z}, {'R', &r}, {'T', &t}, {'S', &s}
    };

    for (int i = 0; i < 4; i++) {
        if (*v[i].q == 0) continue;
        if (lc > 0 && !ok(sol[lc-1], v[i].c)) continue;

        sol[lc] = v[i].c;
        lc++;
        (*v[i].q)--;

        bt(z, r, t, s);

        (*v[i].q)++;
        lc--;
    }
}

int leggi(const char *f, Inp *in) {
    FILE *fp = fopen(f, "r");
    if (!fp) return 0;
    fscanf(fp, "%d %d %d %d", &in->z, &in->r, &in->t, &in->s);
    fclose(fp);
    return 1;
}

void cerca(const Inp *in) {
    lc = lb = 0;
    bt(in->z, in->r, in->t, in->s);
    printf("Lunghezza max: %d\n", lb);
    printf("Collana: %s\n", best);
}