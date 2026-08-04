#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int a[N];

void gen_random(int upper_bound)
{
    for (int i = 0; i < N; i++)
        a[i] = rand() % upper_bound;
}


int count_ten(int n){       //计算位数
    int count = 0;
    if(n == 0)
        count += 1;
    for(; n > 0; count++)
        n /= 10;
    return count;
}

void fill_spaces(int count){
    for(int i = 0; i < count; i++)
        printf(" ");
}

int main(void)
{
    srand(time(NULL));
    int upper_bound, i, hisg_MAX;
    if(scanf("%d", &upper_bound) != 1 || upper_bound <= 0){     //!=1表示没有正确输入，比如输入符号等
        printf("Invalid Input.\n");
        return 1;
    }

    int histogram[upper_bound], height[upper_bound]; // 一定要全部初始化为0
    for (i = 0; i < upper_bound; i++)
        histogram[i] = 0;

    gen_random(upper_bound);

    for (i = 0; i < N; i++)
        histogram[a[i]]++;

    for(i= 0; i < upper_bound; i++)
        height[i] = histogram[i];

    for(i = 1, hisg_MAX = histogram[0]; i < upper_bound; i++){
        if(histogram[i] > hisg_MAX)
            hisg_MAX = histogram[i];
    }

    for (i = 0; i < upper_bound; i++)
        printf("histogram[%d] = %d\n", i, histogram[i]);

    for (i = 0; i < upper_bound; i++){
        printf("%d", i);
        fill_spaces(1);
    }
    
    printf("\n");
    for (i = 0; i < hisg_MAX; i++)
    {
        for (int j = 0; j < upper_bound; j++)
        {
            if (height[j] > 0)
            {
                printf("*");
                height[j]--;
            }
            else
            {
                printf(" ");
            }
            fill_spaces(count_ten(j));
        }
        printf("\n");
    }
    return 0;
}