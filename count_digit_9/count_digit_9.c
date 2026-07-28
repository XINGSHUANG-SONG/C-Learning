#include <stdio.h>

int main(void) {
    int n = 1;
    int count = 0;
    while (n <= 100) {
        if (n % 10 == 9)count += 1;
        if (n / 10 == 9)count += 1;
        ++n;
    }
    printf("The number of 9 in 1~100 is %d.\n", count);
    return 0;
}