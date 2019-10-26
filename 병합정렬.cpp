#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
int arr[SIZE];

void Merge(int *arr,int left, int mid, int right)
{
	int f_idx = left, r_idx = mid+1, s_idx = left;
	int* n_arr = (int*)malloc(sizeof(int) * SIZE);
	
	while (f_idx <= mid && r_idx <= right)
	{
		if (arr[f_idx] < arr[r_idx])
			n_arr[s_idx++] = arr[f_idx++];
		else
			n_arr[s_idx++] = arr[r_idx++];
	}

	while (f_idx <= mid)
		n_arr[s_idx++] = arr[f_idx++];
	
	while (r_idx <= right)	
		n_arr[s_idx++] = arr[r_idx++];

	for (int i = left; i <= right; i++) // left to right만 옮김, 배열전체X
		arr[i] = n_arr[i];

	free(n_arr);
}

void MergeSort(int *arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		Merge(arr, left, mid, right);
	}
}

int main()
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = (i + 3) % 7;
		printf("%d ", arr[i]);
	}
	printf("\n");
		
	MergeSort(arr, 0, SIZE - 1);

	for (int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);

	return 0;
}