#include <stdio.h>

typedef int (*cmp_t)(const void *a, const void *b);

int cmp_int(const void *a, const void *b){
    const int *ia = a;
    const int *ib = b;
    if (*ia < *ib)
        return -1;
    if (*ia > *ib)
        return 1;
    return 0;
}

void insertion_sort(void *d[], int num, cmp_t cmp){
    void *temp;
    for (int i = 1; i < num; i++) {
        temp = d[i];
        int j = i;
        
        while (j > 0 && cmp(temp, d[j - 1]) < 0){
            d[j] = d[j-1];
            j--;
        }
        
        d[j] = temp;
    }
}

int main(void){
    int values[] = {10, 5, 6, 9, 4, 7};

    void *data[] = {
        &values[0], 
        &values[1], 
        &values[2], 
        &values[3], 
        &values[4], 
        &values[5], 
    };

    insertion_sort(data, 6, cmp_int);

    for (int i = 0; i < 6; i++)
        printf("%d ", *(int *)data[i]);
    
    return 0;
}