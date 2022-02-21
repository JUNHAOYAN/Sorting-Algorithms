#include"bucketSort.h"
#include<algorithm>


void buckSort(vector<int>& nums) {
	//define bucket 
	//1. bucket length
	//2. per bucket size
	int maxE = *max_element(nums.begin(), nums.end());
	int maxLen = getMaxLen(maxE);
	int step = 1000;
	if (maxLen < 5) {
		// step is set as 1000 if maxLen larger than 4
		step = (int) pow(10, maxLen - 1);
	}
	int bSize = maxE / step + 1;
	// set per bucket size to be the same as nums size
	vector<vector<int>> bucket(bSize, vector<int> (nums.size(), -1));
	vector<int> bucketSize(bSize, 0);
	// put each element to the corresponding bucket
	for (auto i : nums) {
		int index = i / step;
		bucket[index][bucketSize[index]++] = i;
	}
	// sort at each bucket
	for (int i = 0; i < bSize; i++) {
		insertSort(bucket[i], bucketSize[i]);
	}

	// assign
	int index = 0;
	for (int i = 0; i < bSize; i++) {
		for (int j = 0; j < bucketSize[i]; j++) {
			nums[index++] = bucket[i][j];
		}
	}
}

// calculate the number of digit
// e.x. 100 -> 3
// 1000 -> 4
int getMaxLen(int element) {
	int maxLen = 0;
	while (element >  0) {
		element /= 10;
		maxLen += 1;
	}

	return maxLen;
}


void insertSort(vector<int>& nums, int endIndex) {
	for (int i = 1; i < endIndex; i++) {
		int temp = nums[i], j = i;
		while (j > 0 && temp < nums[j - 1]) {
			nums[j] = nums[j - 1];
			j--;
		}
		nums[j] = temp;
	}
}