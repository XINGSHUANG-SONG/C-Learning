#include <stdio.h>

void print_1_to_n(int n){
    if(n == 0)
        return;
    printf("%d", n);
    printf(" ");
    print_1_to_n(n - 1);
}

int main(void){
    int n;
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Invalid input.\n");
        return 1;
    }
    print_1_to_n(n);
    return 0;
}