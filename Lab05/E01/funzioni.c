#include <stdio.h>
#include "funzioni.h"

static att a[200];
static int n0;
static int best;

static int ok(int i, int j) {
    return a[i].f <= a[j].s || a[j].f <= a[i].s;
}

static void rec(int k, int last, int cur) {
    if (k == n0) {
        if (cur > best)
            best = cur;
        return;
    }

    rec(k+1, last, cur);

    if (last == -1 || a[last].f <= a[k].s) {
        rec(k+1, k, cur + (a[k].f - a[k].s));
    }
}

int leggi(att v[], int max) {
    int n = 0;
    while (n < max && scanf("%d %d", &v[n].s, &v[n].f) == 2)
        n++;
    return n;
}

void attSel(int n, att v[]) {
    for (int i = 0; i < n; i++)
        a[i] = v[i];

    n0 = n;
    best = 0;

    rec(0, -1, 0);

    printf("%d\n", best);
}