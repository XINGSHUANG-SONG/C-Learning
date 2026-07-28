#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int m = 2;

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int *fib = calloc((size_t)n + 1, sizeof(*fib));

    if (fib == NULL) {
        printf("Fail to allocate memory.\n");
        return 1;
    }

    fib[0] = 1;

    if (n >= 1) {
        fib[1] = 1;
    }

    while (m <= n) {
        fib[m] = fib[m - 1] + fib[m - 2];
        ++m;
    }

    printf("%d\n", fib[n]);

    free(fib);
    return 0;
}