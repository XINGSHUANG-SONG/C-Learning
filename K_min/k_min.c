#include <stdio.h>
#define N 9

int a[N] = {1, 22, 13, 4, 4, 88, 5, 6, 89};

int partition(int start, int end)
{
    int i = start + 1, j = end, index = start;
    int pivot = a[start];
    while (i <= j) {
        for (; i <= j ; j--) {
            if (a[j] < pivot) {
                a[index] = a[j];
                index = j--;
                break;
            }
        }
        for (; i <= j; i++) {
            if (a[i] >= pivot) {
                a[index] = a[i];
                index = i++;
                break;    
            }
        }
    }
    a[index] = pivot;
	return index;
}

/* 从start到end之间找出第k小的元素 */
int order_statistic(int start, int end, int k)
{
	//用partition函数把序列分成两半，中间的pivot元素是序列中的第i个;
    int i = partition(start, end) - start + 1;

	if (k == i)
		//返回找到的元素;
        return a[k + start - 1];
	else if (k > i)
		//从后半部分找出第k-i小的元素并返回;
        return order_statistic(i + start, end, k - i);
	else
		//从前半部分找出第k小的元素并返回;
        return order_statistic(start, i + start - 2, k);
}

int main(void) {
    int k_min = order_statistic(1, N-1, 7);
    printf("The k minimum of array a is %d.\n", k_min);
    return 0;
}