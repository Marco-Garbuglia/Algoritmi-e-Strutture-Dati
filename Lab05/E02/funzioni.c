#include <stdio.h>
#include "funzioni.h"

static tile tt[200];
static int bb[30][30];
static int rr[30][30];
static int used[200];

static int R0, C0, ntt;
static int cur, best;

static int riga_ok(int r) {
    for (int j = 1; j < C0; j++) {
        int t1 = bb[r][j-1], t2 = bb[r][j];
        int r1 = rr[r][j-1], r2 = rr[r][j];

        int dx1 = (r1 ? tt[t1].c : tt[t1].b);
        int sx2 = (r2 ? tt[t2].d : tt[t2].a);

        if (dx1 != sx2)
            return 0;
    }
    return 1;
}

static int col_ok(int c) {
    for (int i = 1; i < R0; i++) {
        int t1 = bb[i-1][c], t2 = bb[i][c];
        int r1 = rr[i-1][c], r2 = rr[i][c];

        int giu1 = (r1 ? tt[t1].a : tt[t1].c);
        int su2  = (r2 ? tt[t2].b : tt[t2].d);

        if (giu1 != su2)
            return 0;
    }
    return 1;
}

static int punti_riga(int r) {
    int s = 0;
    for (int j = 0; j < C0; j++) {
        int t = bb[r][j];
        s += tt[t].a;
    }
    return s;
}

static int punti_col(int c) {
    int s = 0;
    for (int i = 0; i < R0; i++) {
        int t = bb[i][c];
        s += tt[t].c;
    }
    return s;
}

static void rec(int r, int c) {
    if (r == R0) {
        if (cur > best)
            best = cur;
        return;
    }

    int nr = r, nc = c + 1;
    if (nc == C0) { nc = 0; nr++; }

    if (bb[r][c] != -1) {
        int old = cur;

        if (c == C0 - 1 && riga_ok(r)) cur += punti_riga(r);
        if (r == R0 - 1 && col_ok(c)) cur += punti_col(c);

        rec(nr, nc);

        cur = old;
        return;
    }

    for (int i = 0; i < ntt; i++) {
        if (used[i]) continue;

        for (int rot = 0; rot < 2; rot++) {

            bb[r][c] = i;
            rr[r][c] = rot;
            used[i] = 1;

            int old = cur;

            if (c == C0 - 1 && riga_ok(r)) cur += punti_riga(r);
            if (r == R0 - 1 && col_ok(c)) cur += punti_col(c);

            rec(nr, nc);

            cur = old;
            used[i] = 0;
        }
    }

    bb[r][c] = -1;
    rr[r][c] = -1;
}

void solve(tile t[], int nt, int b[][30], int r[][30], int R, int C) {
    ntt = nt;
    R0 = R;
    C0 = C;

    for (int i = 0; i < nt; i++) {
        tt[i] = t[i];
        used[i] = 0;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            bb[i][j] = b[i][j];
            rr[i][j] = r[i][j];

            if (bb[i][j] != -1)
                used[ bb[i][j] ] = 1;
        }
    }

    cur = 0;
    best = 0;

    rec(0, 0);

    printf("%d\n", best);
}