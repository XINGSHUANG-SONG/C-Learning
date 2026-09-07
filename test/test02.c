#include <stdio.h>

typedef int (*op_t)(int, int);

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

op_t choose_op(char symbol){
    if (symbol == '-')
        return sub;
    else if (symbol == '+')
        return add;
    else
        return NULL;
}

int main(void){
    op_t op = choose_op('?');
    if (op == NULL) {
        printf("unsupported operator.\n");
        return 1;
    }
    printf("%d\n", op(8, 3));

    return 0;
}