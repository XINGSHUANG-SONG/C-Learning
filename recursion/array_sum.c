#include <stdio.h>

int array_sum(int a[], int index, int length){
    if(index == 0){
        return a[index];
    }
    return a[index] + array_sum(a, index - 1, length);
}

int main(void){
    int length;
    if(scanf("%d", &length) != 1 || length <= 0){
        printf("Invalid input.\n");
        return 1;
    }
    int a[length], index = length - 1;
    for(int i = 0; i < length; i++){
        a[i] = i + 1;
    }
    printf("The array_sum is %d.\n", array_sum(a, index, length));
    return 0;
}