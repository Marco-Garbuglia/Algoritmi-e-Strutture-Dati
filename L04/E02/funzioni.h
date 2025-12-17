#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAXA 20
#define MAXC 10
#define MAXLEN 260

typedef struct {
    int A;
    int C[MAXA];
    char brani[MAXA][MAXC][MAXLEN];
} Play;

int leggi(const char *f, Play *p);
void genera(const Play *p);

#endif