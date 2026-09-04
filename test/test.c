#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int number;
    char *msg;
}unit_t;

int alloc_unit(unit_t **out){
    if (out == NULL)
        return -1;
    unit_t *temp = malloc(sizeof *temp);
    if (temp == NULL)
        return -1;
    temp -> msg = malloc(20);
    if (temp -> msg == NULL) {
        free(temp);
        return -1;
    }
    temp -> number = 3;
    strcpy(temp->msg, "Hello World!");
    *out = temp;
    return 0;
}

void free_unit(unit_t *p){
    if (p == NULL) return;
    free(p->msg);
    free(p);
}