#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y){
    int count = 0;
    unsigned int result = 0;
    while (y != 0) {
        if ((y & 1) != 0)
            result += x << count;
        count++;
        y >>= 1;
    }
    return result;
}

int main(void){
    unsigned int x, y;
    while (1) {
        printf("Please input integer x and y for multiplication.(x, y > 0)\n");
        if (scanf("%u %u", &x, &y) != 2) {
            printf("Invalid input.\n");
            return 1;
        }
        printf("The multiplication of x and y is %u.\n", multiply(x, y));
    }
    return 0;
}