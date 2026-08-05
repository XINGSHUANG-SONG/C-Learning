#include <stdio.h>

#define N 4
#define M 4

int a[N] = {1, 2, 3, 4};
int result[M];

void combination(int start, int count)
{
    if (count == M) {
        for (int i = 0; i < M; i++)
            printf("%d ", result[i]);

        printf("\n");
        return;
    }

    for (int i = start; i < N; i++) {
        result[count] = a[i];
        combination(i + 1, count + 1);
    }
}

int main(void)
{
    combination(0, 0);

    return 0;
}