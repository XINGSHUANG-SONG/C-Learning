#include <stdio.h>

double mysqrt(double y) {
    double x, start = 0.0, end = ((y >= 1) ? y : 1);
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
    double y;
    printf("Please input a number to y.(y > 0)\n");
    if (scanf("%lf", &y) != 1 || y < 0) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("%f\n", mysqrt(y));
    return 0;
}