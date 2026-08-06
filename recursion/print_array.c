#include <stdio.h>

void print_array(int a[], int index, int length){
    if(index == -1){
        return;
    }
    print_array(a, index - 1, length);
    printf("%d ", a[index]);
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
    print_array(a, index, length);
    return 0;
}