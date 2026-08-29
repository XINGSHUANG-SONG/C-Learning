#include <stdio.h>

int countbit(unsigned int x){
    int count = 0;
    while (x != 0) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int main(void){
    unsigned int x;
    while (1) {
        if (scanf("%u", &x) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        printf("The number of 1 bits in x is %d.\n", countbit(x));
    }
    return 0;
}