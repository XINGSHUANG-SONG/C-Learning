#include <stdio.h>
#define N 7

int a[N] = {4, 6, 8, 10, 2, 4, 9};

int partition(int start, int end)
{
	// 从a[start..end]中选取一个pivot元素（比如选a[start]为pivot）;
    int i = start, j = end, k = 0, mid;
    int pivot = a[i];
	// 在一个循环中移动a[start..end]的数据，将a[start..end]分成两半，
    while (i <= j) {
        if (a[i] < pivot && i > 0) {
            int temp = a[i];
            a[i] = pivot;
            a[i - 1] = temp;
            i++;
        } else if (a[i] > pivot) {
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            j--;
        } else {
            i++;
        }
    }
    mid = i - 1;
	// 使a[start..mid-1]比pivot元素小，a[mid+1..end]比pivot元素大，而a[mid]就是pivot元素;
	return mid;
}

void quicksort(int start, int end)
{
	int mid;
	if (end > start) {
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}
}

int main(void) {
    quicksort(0, N - 1);
    return 0;
}