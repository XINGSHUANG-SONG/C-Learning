#include <stdio.h>

int print_diamond(int n, char m){
    if(n % 2 == 0){
        printf("Invlid input.");
        return 1;
    }
    for(int i = 1; i <= n; i++){
        if(i <= (n + 1) / 2){
            int floor = (n + 1) / 2 - i + 1;
            int ceil = n - (n + 1) / 2 + i;
            for(int j = floor; j <= ceil; j++){
                if(floor > 1 && j < floor + 1){
                    for(int count = 1;count < floor;count++){
                        printf(" \t");
                    }
                };
                printf("%c\t", m);
                if(j == ceil)printf("\n");
            }
        }else if(i > (n + 1) / 2){
            int floor = i - (n + 1) / 2 + 1;
            int ceil = n - i + (n + 1) / 2;
            for(int j = floor; j <= ceil; j++){
                if(floor > 1 && j < floor + 1){
                    for(int count = 1;count < floor;count++){
                        printf(" \t");
                    }
                };
                printf("%c\t", m);
                if(j == ceil)printf("\n");
            }
        }
    }
    return 0;
}

int main(void){
    int n;
    char m;
    scanf("%d", &n);
    scanf("%c", &m);
    print_diamond(n, m);
    return 0;
}