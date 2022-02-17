#pragma once
#include <iostream>
#include <vector>
using namespace std;


void quickSort(vector<int>& nums, int left, int right);

void swap(vector<int>& nums, int i, int j);

int partition(vector<int>& nums, int left, int right);