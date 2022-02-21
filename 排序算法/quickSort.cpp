#include"quickSort.h"

/*
nlog(n)
*/
void quickSort(vector<int>& nums, int left, int right) {
	if (left >= right) return;
	int pivotIndex = partition2(nums, left, right);
	quickSort(nums, left, pivotIndex - 1);
	quickSort(nums, pivotIndex + 1, right);
}


void quickSort2(vector<int>& nums, int left, int right) {
	if (left >= right) return;
	int randIndex = rand() % (right - left + 1) + left;
	swap(nums, left, randIndex);
	// draw the flow path and then you could understand why the lt, gt are initialized to the left, right + 1
	int pivot = nums[left], lt = left, gt = right + 1, i = left + 1;
	// [left + 1, lt] < pivot
	// (lt, i) = pivot
	// [gt, right] > pivot
	while (i < gt) {
		if (nums[i] < pivot) {
			swap(nums, ++lt, i++);
		}
		else if (nums[i] > pivot) {
			swap(nums, --gt, i);
		}
		else {
			i++;
		}
	}
	swap(nums, left, lt);
	quickSort2(nums, left, lt - 1);
	quickSort2(nums, gt, right);
}


int partition(vector<int>& nums, int left, int right) {
	// random select the pivot
	int randomIndex = rand() % (right - left + 1) + left;
	swap(nums, left, randomIndex);
	// [left + 1, lt] <= pivot
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

int partition2(vector<int>& nums, int left, int right) {
	// random select the pivot
	int randomIndex = rand() % (right - left + 1) + left;
	swap(nums, left, randomIndex);
	int pivot = nums[left]; // pivot value
	// all in [left + 1, le) <= pivot
	// all in (ge, right] >= pivot
	// le > ge stop
	int le = left + 1, ge = right;
	while (ge >= le) {
		// postion with value >= pivot
		while (le <= ge && nums[le] < pivot) {
			le++;
		}
		// postion with value <= pivot
		while (le <= ge && nums[ge] > pivot) {
			ge--;
		}
		if (ge < le) {
			break;
		}
		swap(nums, le++, ge--);
	}
	swap(nums, left, ge);

	return ge;
}

void swap(vector<int>& nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}