#include <stdio.h>

double mypow(double x, int n)
{
    double result = 1.0;
    double base = x;
    int power = n;

    if (power <= 1)
        return x;
    if (power % 2 == 1)
        result *= base;

    base *= base;
    power /= 2;

    return  result * mypow(base, power);
}

int main(void){
    while (1) {
        double x;
        printf("Please enter the numerical value x (of double type)\nx:");
        if (scanf("%lf", &x) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        int n;
        printf("Please input the power n (of integer type, n > 0)\nn:");
        if (scanf("%d", &n) != 1 || n <= 0) {
            printf("Invalid input.\n");
            return 1;
        }
        printf("%0.12lf\n", mypow(x, n));
    }
    return 0;
}