#include"countSort.h"
#include<algorithm>


/*
counting sort
O(n + k), k为数组最大值
适用场景：
-数据范围较小
-重复数字较多
比如，年龄，考试成绩
*/
void countSort(vector<int>& nums) {
	vector<int> result(nums.size()), count(*max_element(nums.begin(), nums.end()) + 1);
	//count 
	for (int i = 0; i < nums.size(); i++) {
		count[nums[i]] += 1;
	}
	int index = 0;
	for (int i = 0; i < count.size(); i++) {
		while (count[i] > 0) {
			result[index++] += i;
			count[i]--;
		}
	}

	for (int i = 0; i < result.size(); i++) {
		nums[i] = result[i];
	}
}

/*
O(n+k)
*/
void countSort2(vector<int>& nums) {
	vector<int> result(nums.size()), count(*max_element(nums.begin(), nums.end()) + 1); 
	int index = 0;
	// count
	for (int i = 0; i < nums.size(); i++) {
		count[nums[i]] += 1;
	}
	// aggregate
	for (int i = 1; i < count.size(); i++) {
		count[i] += count[i - 1];
	}

	// sort
	for (int i = nums.size() - 1; i > 0; i--) {
		result[--count[nums[i]]] = nums[i];
	}

	for (int i = 0; i < result.size(); i++) {
		nums[i] = result[i];
	}
}