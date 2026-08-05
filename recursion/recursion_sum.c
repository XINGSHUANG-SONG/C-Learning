#include <stdio.h>

int sum(int n){
    if(n == 0)
        return 0;
    return n + sum(n - 1);
}

int main(void){
    int n;
    if(scanf("%d", &n) != 1 || n < 0){
        printf("Invalid input.\n");
        return 1;
    }
    printf("sum from 1 to %d is %d.\n", n, sum(n));
    return 0;
}