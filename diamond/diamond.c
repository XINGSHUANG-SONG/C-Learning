#include <stdio.h>

int print_diamond(int n, char m){
    if(n <= 0 || n % 2 == 0){
        printf("Invalid input.\n");
        return 1;
    }
    int i = 1;
    int left, right;
    for(; i <= n; i++){
        if(i <= (n + 1) / 2){
            left = (n + 1) / 2 - i + 1;
            right = n - (n + 1) / 2 + i;
            for(int j = left; j <= right; j++){
                if(left > 1 && j == left){
                    for(int count = 1;count < left;count++){
                        printf("       ");
                    }
                };
                printf("%c      ", m);
                if(j == right)printf("\n");
            }
        }else if(i > (n + 1) / 2){
            left = i - (n + 1) / 2 + 1;
            right = n - i + (n + 1) / 2;
            for(int j = left; j <= right; j++){
                if(left > 1 && j == left){
                    for(int count = 1;count < left;count++){
                        printf("       ");
                    }
                }
                printf("%c      ", m);
                if(j == right)printf("\n");
            }
        }
    }
    return 0;
}

int main(void){
    int n;
    char m;
    scanf("%d %c", &n, &m);
    print_diamond(n, m);
    return 0;
}