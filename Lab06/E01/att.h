#ifndef ATT_H
#define ATT_H

typedef struct {
    int s;
    int f;
} att_t;

att_t *leggiAtt(char *nome, int *n);
int solveDP(att_t *v, int n, int *sol);
void stampaSol(att_t *v, int *sol, int n);

#endif