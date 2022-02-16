#include <iostream>
#include "bubbleSort.h"

/*
n^2
*/
void bubbleSort(int arr[], int num) {
	for (int i = num; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}