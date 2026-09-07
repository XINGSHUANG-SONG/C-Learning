#include <stdio.h>

double recursion(int x) {
    if (x == 1) return 1.0 - 1.0 / 365.0;
    return (1.0 - x / 365.0) * recursion(x - 1);
}

int main(void){
    int x = 1;
    double a;
    do {
        a = 1.0 - recursion(x);
        printf("%f\n", a);
        x++;
    } while (a < 0.9);
    printf("%d\n", x);
    return 0;
}