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

void merge_sorted(void *a[], int na,
                void *b[], int nb,
                void *out[],cmp_t cmp){
                    int j = 0, ia = 0;
                    for (int ib = 0; ib < nb; ib++){
                        while (ia < na && cmp(b[ib], a[ia]) > 0) {
                            out[j] = a[ia];
                            j++;
                            ia++;
                        }
                        out[j++] = b[ib];
                    }
                    if (ia < na)
                        for (int i = ia; i < na; i++)
                            out[j++] = a[i];
                }

int main(void){
    int a[] = {2, 5, 8};
    int b[] = {1, 5, 9};
    void *out[6];
    void *date_a[] = {
        &a[0], &a[1], &a[2]
    };
    void *date_b[] = {
        &b[0], &b[1], &b[2]
    };
    merge_sorted(date_a, 3, date_b, 3, out, cmp_int);
    for (int i = 0; i < 6; i++)
        printf("%d ", *(int *)out[i]);
    return 0;
}