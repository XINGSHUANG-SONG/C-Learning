#include <stdio.h>
typedef int (*cmp_t)(const void *a, const void *b);

int values[] = {3, 9, 4, 7};

void *data[] = {
    &values[0],
    &values[1],
    &values[2],
    &values[3]
};

int cmp_int(const void *a, const void *b){
    const int *ia = a;
    const int *ib = b;
    if (*ia < *ib)
        return -1;
    if (*ia > *ib)
        return 1;
    return 0;
}

void *max(void *d[], int num, cmp_t cmp){
    void *temp = d[0];
    for (int i = 1; i < num; i++)
        if (cmp(temp, d[i]) < 0)
            temp = d[i];
    return temp;
}

int main(void){
    int *largest = max(data, 4, cmp_int);
    printf("%d\n", *largest);
    return 0;
}