#include <stdio.h>

double mypow(double x, int n){
    int even_count = 0, power = n;
    double base = 1.0, copy = x;
    if (x == 0 || x == 1)
        return x;
    while (power > 1) {
        if (power % 2 == 1) {//处理特殊的情况
            base *= copy;
            power += 1;
        }
        power /= 2;
        even_count++;
        copy *= copy;
    }
    for (int i = 0; i < even_count; i++)
        x *= x;
    x /= base;
    return x;
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