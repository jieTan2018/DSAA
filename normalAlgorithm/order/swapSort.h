#pragma once
#include"generic.h"
/*交换排序：两元素比较，反序则交换。*/
// 1.1 冒泡排序：将每轮的最大数冒起来，排到该轮最后位置。
int* bubbleSort(int* orig_array, int arr_length) {
	for (int i = 0; i < arr_length - 1; i++) {
		for (int j = 0; j < arr_length - i - 1; j++)  // 第 i 个元素，要和它后面的所有元素比较交换。即 i+1 => length-1
		{
			if (orig_array[j] > orig_array[j + 1]) {  // 交换
				int tmp = orig_array[j];
				orig_array[j] = orig_array[j + 1];
				orig_array[j + 1] = tmp;
			}
		}
	}
	return orig_array;
}
//1.2 带标志的冒泡排序：
int* bubbleFlagSort(int* orig_array, int arr_length) {
	bool flag;
	for(int i = 0; i < arr_length - 1; i++) {
		//cout << "i：" << i << endl;
		flag = true;
		for (int j = 0; j < arr_length - 1 - i; j++) {
			if (orig_array[j] > orig_array[j + 1]) {  // 交换
				int tmp = orig_array[j];
				orig_array[j] = orig_array[j + 1];
				orig_array[j + 1] = tmp;
				flag = false;
			}
		}
		if (flag)return orig_array;
	}
	return orig_array;
}

//2、快速排序（重点！）
//2.1、一次划分，返回中轴
int parttion(int* orig_array, int start, int end) {
	int l = start, r = end;  // l: left, r: right
	while (l < r)
	{
		//1. 右侧扫描
		while (l < r && orig_array[l] < orig_array[r]) r--;
		if (l < r) {
			int tmp = orig_array[r];
			orig_array[r] = orig_array[l];
			orig_array[l++] = tmp;
		}
		//2. 左侧扫描
		while (l < r && orig_array[l] <= orig_array[r])l++;
		if (l < r) {
			int tmp = orig_array[r];
			orig_array[r--] = orig_array[l];
			orig_array[l] = tmp;
		}
	}
	return l;
}
//2.2、快排：比较次数中等，在记录很多的情况下，其记录移动次数远小于折半、冒泡等排序。（记录移动次数少，所以效率高）
int* quickSort(int* orig_array, int start, int end) {
	if (start < end) {  // 递归退出条件：start >= end
		int povit = parttion(orig_array, start, end);
		quickSort(orig_array, start, povit - 1);
		quickSort(orig_array, povit + 1, end);
	}
	return orig_array;
}
