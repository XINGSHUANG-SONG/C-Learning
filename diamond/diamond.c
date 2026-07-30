#include <stdio.h>

void print_diamond(int n, char ch){
    int middle = (n + 1) / 2;
    for(int i = 1; i <= n; i++){
        int left, right;    //放在循环里，缩小变量作用域
        if(i <= middle){
            left = middle - i + 1;
            right = n - middle + i;
        }else{
            left = i - middle + 1;
            right = n - i + middle;
        }
        for(int count = 1;count < left;count++){
            printf("  ");
        }
        for(int j = left; j <= right; j++){
            printf("%c", ch);
            if(j < right)printf(" ");
        }
        printf("\n");       //每一行结束都要换行
    }
}

int main(void){
    int n;
    char ch;
    if(scanf("%d %c", &n, &ch) != 2){
        printf("Invalid input.\n");
        return 1;
    }
    if(n <= 0 || n % 2 == 0){
        printf("Must be a positive odd integer.\n");
        return 1;
    }
    print_diamond(n, ch);
    return 0;
}