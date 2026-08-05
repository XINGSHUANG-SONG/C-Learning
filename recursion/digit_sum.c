#include <stdio.h>

int digit_sum(int n){
    if(n == 0){
        return 0;
    }
    return n % 10 + digit_sum(n / 10);
}
int main(void){
    int n;
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Invalid input.\n");
        return 1;
    }
    printf("The digit_sum is %d.\n", digit_sum(n));
    return 0;
}