#include "mergeSort.h"

/*
nlog(n)
*/
void mergeSort(vector<int>& nums, int left, int right) {
	if (left == right) return;
	// left [left, mid], (mid, right]
	int mid = left + (right - left) / 2;
	// devide
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	// conquer
	mergeTwoArr(nums, left, mid, right);
}


void mergeTwoArr(vector<int>& nums, int left, int mid, int right) {
	// vector len, left arr starting index, right arr starting index
	int len = right - left + 1, leftIndex = 0, rightIndex = mid - left + 1;
	int* temp = new int[len];
	for (int i = 0; i < len; i++) {
		temp[i] = nums[left + i];
	}

	for (int i = 0; i < len; i++) {
		// left [left, mid], (mid, right]
		// check whether the index exceeds the boardline or not
		if (leftIndex == mid - left + 1) {
			nums[left + i] = temp[rightIndex];
			rightIndex++;
		}
		else if (rightIndex == right - left + 1) {
			nums[left + i] = temp[leftIndex];
			leftIndex++;
		}
		else if (temp[leftIndex] <= temp[rightIndex]) {
			nums[left + i] = temp[leftIndex];
			leftIndex++;
		}
		else {
			nums[left + i] = temp[rightIndex];
			rightIndex++;
		}
	}
	
	delete[] temp;
}