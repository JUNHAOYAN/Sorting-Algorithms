#include"quickSort.h"

/*
nlog(n)
*/
void quickSort(vector<int>& nums, int left, int right) {
	if (left >= right) return;
	int pivotIndex = partition(nums, left, right);
	quickSort(nums, left, pivotIndex - 1);
	quickSort(nums, pivotIndex + 1, right);
}


int partition(vector<int>& nums, int left, int right) {
	int pivot = nums[left]; // pivot value
	int lt = left; // store the position of the last value that is smaller than the pivot
	for (int i = left + 1; i < right + 1; i++) {
		if (nums[i] <= pivot) {
			lt++;
			swap(nums, i, lt);
		}
	}
	swap(nums, lt, left);

	return lt;
}


void swap(vector<int>& nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}