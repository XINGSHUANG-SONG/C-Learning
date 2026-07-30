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
        }else{
            left = i - (n + 1) / 2 + 1;
            right = n - i + (n + 1) / 2;
        }
        for(int count = 1;count < left;count++){
            printf("       ");
        }
        for(int j = left; j <= right; j++){
            printf("%c      ", m);
            if(j == right)printf("\n");
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