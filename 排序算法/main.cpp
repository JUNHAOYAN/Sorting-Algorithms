#include <iostream>
#include <vector>
#include"selectSort.h"
#include"bubbleSort.h"
#include"insertSort.h"
#include"mergeSort.h"
using namespace std;

void print(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void testSelectSort() {
	int arr[] = { 1, 8, 20, 20, 5, 7, 8 };
	int num = sizeof(arr) / sizeof(int);
	selectSort(arr, num);
	print(arr, num);
}

void testBubbleSort() {
	int arr[] = { 1, 8, 100, 100, 5, 7, 8 };
	int num = sizeof(arr) / sizeof(int);
	bubbleSort(arr, num);
	print(arr, num);
}

void testInsertSort() {
	int arr[] = { 1, 8, 100, 20, 5, 7, 8 };
	int num = sizeof(arr) / sizeof(int);
	insertSort2(arr, num);
	print(arr, num);
}

void testMergeSort() {
	int arr[] = { 1, 8, 100, 20, 5, 7, 8 , 4, 67, 88};
	vector<int> v(10);
	for (int i = 0; i < 10; i++) {
		v[i] = arr[i];
	}
	mergeSort(v, 0, v.size() - 1);
	print(v);
}

void test00() {
	int *temp = new int[10];
	// temp指针在结束循环的时候是指在数组最后的一个元素的后一个位置
	for (int i = 0; i < 10; i++) {
		(*temp) = i;
		temp++;
	}
	for (int i = 0; i < 10; i++) {
		temp--;
		cout << *temp << endl;
	}

	for (int i = 0; i < 10; i++) {
		temp[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		cout << temp[i] << endl;
	}
}

int main() {
	testMergeSort();
	return 0;
}