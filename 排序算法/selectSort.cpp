#include <iostream>
#include "selectSort.h"
using namespace std;


/*
n^2
*/
void selectSort(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++)
		{
			if (arr[j] < arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
}