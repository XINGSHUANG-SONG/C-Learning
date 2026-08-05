#include <stdio.h>

void print_1_to_n(int n){
    if(n == 0)
        return;
    print_1_to_n(n - 1);
    printf("%d", n);
    printf(" ");
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