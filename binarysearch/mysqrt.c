#include <stdio.h>

double mysqrt(double y) {
    double x, start = 0.0, end = ((y >= 1) ? y : 1);
    while (1) {
        x = (start + end) / 2.0;
        if ((x*x - y) >= 0.0000000001)
            end = x;
        else if((x*x - y) <= -0.0000000001)
            start = x;
        else
            return x;
        //printf("%f\n", x);
    }
}

int main(void) {
    while (1) {
        double y;
        printf("Recommended range: 1e-6 to 1e8 for obtaining more accurate results.\n");        
        printf("Please input a number to y.(y > 0)\n");
        if (scanf("%lf", &y) != 1 || y <= 0) {
            printf("Invalid input.\n");
            return 1;
        }
        printf("%0.10lf\n", mysqrt(y));
    }
    return 0;
}