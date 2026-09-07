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

int binarysearch(void *d[], int num, const void *key, cmp_t cmp){
    int start = 0, end = num;
    int mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (cmp(d[mid], key) < 0) {
            start = mid+1;
        } else if (cmp(d[mid], key) > 0) {
            end = mid;
        } else 
            return mid;
    }
    return -1;
}

int main(void){
    int values[] = {2, 5, 5, 8, 9};
    void *data[] = {
        &values[0], 
        &values[1], 
        &values[2], 
        &values[3], 
        &values[4]
    };
    int a;
    while (1) {
        if (scanf("%d", &a) != 1) {
            printf("Invalid Input.\n");
            return 1;
        }
        void *key = &a;
        printf("%d\n", binarysearch(data, 5, key, cmp_int));
    }
    return 0;
}