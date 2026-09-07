#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int number;
    char *msg;
}unit_t;

unit_t *alloc_unit(void){
    unit_t *temp = malloc(sizeof *temp);
    if (temp == NULL)
        return NULL;
    temp->msg = malloc(20);
    if (temp->msg == NULL) {
        free(temp);
        return NULL;
    }
    temp->number = 3;
    strcpy(temp->msg, "Hello World!");
    return temp;
}

void free_unit(unit_t *p){
    if (p == NULL) return;
    free(p->msg);
    free(p);
}