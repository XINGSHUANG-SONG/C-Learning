#include <stdio.h>

int array_max(int a[], int index){
    if(index == 0){
        return a[0];
    }
    int max = array_max(a,index - 1);
    return (a[index] >= max ? a[index] : max);
}

int main(void){
    int length;
    printf("The length of array is ");
    if(scanf("%d", &length) != 1 || length <= 0){
        printf("Invalid input.\n");
        return 1;
    }
    int a[length], index = length - 1;
    for(int i = 0; i < length; i++){
        printf("The a[%d] is ", i);
        if(scanf("%d", &a[i]) != 1){
            printf("Invalid input.\n");
            return 1;
        }
    }
    printf("The array_max is %d.\n", array_max(a, index));
    return 0;
}