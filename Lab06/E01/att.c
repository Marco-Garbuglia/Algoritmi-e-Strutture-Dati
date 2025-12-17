#include <stdio.h>
#include <stdlib.h>
#include "att.h"

static int cmp(const void *a, const void *b) {
    att_t *x = (att_t *)a;
    att_t *y = (att_t *)b;
    return x->f - y->f;
}

att_t *leggiAtt(char *nome, int *n) {
    FILE *fp = fopen(nome, "r");
    int i = 0;
    att_t *v;

    if (!fp) return NULL;

    fscanf(fp, "%d", n);
    v = malloc(*n * sizeof(att_t));
    for (i = 0; i < *n; i++)
        fscanf(fp, "%d %d", &v[i].s, &v[i].f);

    fclose(fp);

    qsort(v, *n, sizeof(att_t), cmp);
    return v;
}

int solveDP(att_t *v, int n, int *sol) {
    int *dp = malloc(n * sizeof(int));
    int *pred = malloc(n * sizeof(int));
    int i, j;

    for (i = 0; i < n; i++) {
        dp[i] = 1;
        pred[i] = -1;

        for (j = 0; j < i; j++) {
            if (v[j].f <= v[i].s && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                pred[i] = j;
            }
        }
    }

    int best = 0, pos = 0;
    for (i = 0; i < n; i++)
        if (dp[i] > best) {
            best = dp[i];
            pos = i;
        }

    int k = best - 1;
    while (pos != -1) {
        sol[k] = pos;
        k--;
        pos = pred[pos];
    }

    free(dp);
    free(pred);
    return best;
}

void stampaSol(att_t *v, int *sol, int n) {
    int i;
    printf("Attività scelte:\n");
    for (i = 0; i < n; i++)
        if (sol[i] >= 0)
            printf("%d %d\n", v[sol[i]].s, v[sol[i]].f);
}