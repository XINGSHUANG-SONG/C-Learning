#include <stdio.h>

float mysqrt(float y) {
    float x, start = 0.0, end = ((y >= 1) ? y : 1);
    while (1) {
        x = (start + end) / 2.0;
        if ((x*x - y) >= 0.001)
            end = x;
        else if((x*x - y) <= -0.001)
            start = x;
        else
            return x;
        //printf("%f\n", x);
    }
}

int main(void) {
    float y;
    printf("Please intput a number to y.(y > 0)\n");
    if (scanf("%f", &y) != 1 || y < 0) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("%f\n", mysqrt(y));
    return 0;
}