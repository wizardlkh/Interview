#include<stdio.h>
#define MAX 10
int N, arr[MAX];

void swap(int arr[], int ia, int ib)
{
	int temp = arr[ia];
	arr[ia] = arr[ib];
	arr[ib] = temp;
}

int pivot(int arr[], int left, int right)
{
	int p = left, low = left+1, high = right;

	while (low <= high)
	{
		while (arr[low] < arr[p])
			low++;

		while (arr[high] > arr[p])
			high--;

		if (low <= high)
			swap(arr, low, high);
	}

	swap(arr, p, high);
	return high;
}

void QSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int p = pivot(arr, left, right);
		QSort(arr, left, p - 1);
		QSort(arr, p+1, right);
	}
}

int main()
{
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = (i + 5) % 10;

		printf("%d ", arr[i]);
	}
	printf("\n");
		
	QSort(arr, 0, MAX-1);

	for (int i = 0; i < MAX; i++)
		printf("%d ", arr[i]);


	return 0;
}