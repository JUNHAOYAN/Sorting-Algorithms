#include <iostream>
#include <vector>
#include"selectSort.h"
#include"bubbleSort.h"
#include"insertSort.h"
#include"quickSort.h"
#include"mergeSort.h"
#include"countSort.h"
#include"bucketSort.h"
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


void testQuickSort() {
	int arr[] = { 1, 8, 100, 25, 5, 7, 8 , 4, 67, 75 };
	vector<int> v(10);
	for (int i = 0; i < 10; i++) {
		v[i] = arr[i];
	}
	quickSort2(v, 0, v.size() - 1);
	print(v);
}

void testCountSort() {
	int arr[] = { 1, 8, 100, 25, 5, 7, 8 , 4, 67, 75 };
	vector<int> v(10);
	for (int i = 0; i < 10; i++) {
		v[i] = arr[i];
	}
	countSort2(v);
	print(v);
}


void testBucketSort() {
	int arr[] = { 1, 8, 100, 25, 5, 7, 8 , 4, 67, 75, 101, 130, 140, 150, 189 };
	int len = sizeof(arr) / sizeof(arr[0]);
	vector<int> v(len);
	for (int i = 0; i < len; i++) {
		v[i] = arr[i];
	}
	buckSort(v);
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
	testBucketSort();
	return 0;
}