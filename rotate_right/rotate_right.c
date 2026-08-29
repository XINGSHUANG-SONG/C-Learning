#include <stdio.h>

unsigned int rotate_right(unsigned int x, int bit){
    bit %= 32;
    if (bit == 0)
        return x;
    unsigned int y = (x >> bit) | (x << (32 - bit));
    return y;
}

int main(void){
    unsigned int x;
    int bit;
    while (1) {
        printf("Please input hexadecimal number x and integer bit.(x > 0, bit >= 0)\n");
        if (scanf("%x %d", &x, &bit) != 2 || x == 0 || bit < 0) {
            printf("Invalid input.\n");
            return 1;
        }
        printf("The rotate_right bits for x is 0x%x.\n", rotate_right(x, bit));
    }
    return 0;
}