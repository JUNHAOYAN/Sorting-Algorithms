#include "insertSort.h"


/*
n^2
*/
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void insertSort(int arr[], int num) {
	for (int i = 1; i < num; i++) {
		for (int j = i - 1; arr[j] > arr[j+1] && j >= 0; j--) {
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
	}
}


void insertSort2(int arr[], int num) {
	// find minimum
	int minIndex = 0;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] < arr[minIndex]) {
			minIndex = i;
		}
	}
	swap(arr, 0, minIndex);
	for (int i = 1; i < num; i++) {
		int j = i - 1;
		int temp = arr[i];
		while (temp < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}