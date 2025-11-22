#ifndef LAE_H
#define LAE_H
#include <stdio.h>

typedef struct {
    FILE * pointer;
    char content[8192];
    char name[];
} lae_file_t;

void lae_run(lae_file_t lae_file);

#endif
