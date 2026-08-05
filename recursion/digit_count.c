#include <stdio.h>

int digit_count(int n){
    if(n == 0){
        return 0;
    }
    return 1 + digit_count(n / 10);
}

int main(void){
    int n;
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Invalid input.\n");
        return 1;
    }
    printf("The digit_count is %d", digit_count(n));
    return 0;
}