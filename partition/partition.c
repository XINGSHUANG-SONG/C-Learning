#include <stdio.h>
#define N 7

int a[N] = {4, 6, 8, 10, 2, 4, 9};

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