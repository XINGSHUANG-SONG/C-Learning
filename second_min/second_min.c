#include <stdio.h>
#define N 9

int a[N] = {8, 2, 5, 7, 9, 13, 22, 1, 5};

int second_min(){
    int min = a[0], second_min = a[1];
    for (int i = 1; i < N; i++) {
        if (min > a[i]) {
            second_min = min;
            min = a[i];
        } else {
            if ((second_min == min 
                || second_min >a[i]) 
                && min != a[i]) {
                second_min = a[i];
            }
        }
    }
    return second_min;
}

int main(void){
    int second_min_of_a = second_min();
    if (second_min_of_a){
        printf("The second minimum value of array a is %d.\n", second_min_of_a);
    }
    return 0;
}