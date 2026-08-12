#include <stdio.h>
#define N 7

int a[N] = {4, 6, 8, 10, 2, 4, 9};

int partition(int start, int end)
{
    int i = start + 1, j = end;
    int pivot = a[start];
    while (i <= j) {
        if (a[i] < pivot) {
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
	return i - 1;
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