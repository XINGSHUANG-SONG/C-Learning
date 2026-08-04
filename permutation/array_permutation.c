#include <stdio.h>
#define N 4

int a[N];

void permutation(int start)
{
    if (start == N - 1) {   /* 已经到最后一个位置 */
        for(int i = 0; i < N; i++)  /* 打印数组 */
        {
            printf("%d", a[i]);
            printf(" ");
        }
        printf("\n");
        return; //返回上一层（很重要）
    }

    for (int i = start; i < N; i++) {
        /* 交换当前元素和第i个元素 */
        int temp1 = a[start];
        a[start] = a[i];
        a[i] = temp1;
        /* 递归处理下一个位置 */
        permutation(start + 1);
        /* 交换回来 */
        int temp2 = a[start];
        a[start] = a[i];
        a[i] = temp2;
    }
}

int main(void){
    int start = 0;
    for(int i = 0; i < N; i++)
    {
        a[i] = i + 1;
    }
    permutation(start);
    return 0;
}