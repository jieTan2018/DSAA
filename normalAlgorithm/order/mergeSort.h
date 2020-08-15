#pragma once
#include<iostream>
// 归并排序
// 1、一次归并排
void merge(int* orig_arr, int* order_arr, int sta, int mid, int end) {  // orig_arr：在某个h内，已基本有序的序列；order_arr：归并h步长数据后，有序序列存放的地方。
	// 对要合并的两个有序序列排序（两个序列分别放置在前、后半段）
	int i = sta, j = mid + 1, k = sta;  // i：，j：，k：
	//int order_arr[6];
	//for (int i = 1; i < 6; i++)std::cout << order_arr[i] << " ";
	while (i <= mid && j <= end)
	{
		if (orig_arr[i] < orig_arr[j])order_arr[k++] = orig_arr[i++];
		else order_arr[k++] = orig_arr[j++];
	}
	if (i <= mid) {
		while (i <= mid) order_arr[k++] = orig_arr[i++];
	}
	else
	{
		while (j <= end) order_arr[k++] = orig_arr[j++];
	}
}
// 2.1 （非递归）归并排序
// i. 一趟归并排序
void mergePass(int* orig_arr, int* order_arr, int arr_length, int h) {
	int step = 2 * h;
	int sta = 1;
	int end = sta + step - 1;
	while (end < arr_length)
	{
		merge(orig_arr, order_arr, sta, sta + h - 1 , end);
		/*for (int i = sta; i <= end; i++)std::cout << order_arr[i] << " ";
		std::cout << "\n";*/
		sta += step;
		end = sta + step - 1;
	}
	int remain = arr_length - sta;
	if (remain > h)merge(orig_arr, order_arr, sta, sta + h - 1 , arr_length - 1);
	else
	{
		while (sta < arr_length)order_arr[sta] = orig_arr[sta++];
	}
}
// ii. 归并排序
int* mergeSort(int* orig_arr, int* order_arr, int arr_length) {
	int h = 1;
	while (h < arr_length)
	{
		mergePass(orig_arr, order_arr, arr_length, h);
		h *= 2;
		mergePass(order_arr, orig_arr, arr_length, h);
		h *= 2;
	}
	return order_arr;
}

// 2.2 （递归）归并排序
void mergeSort2(int* orig_arr, int* ret_arr, int sta, int end) {
	if (sta == end) ret_arr[sta] = orig_arr[sta];
	else
	{
		int mid = (sta + end) / 2;
		mergeSort2(orig_arr, ret_arr, sta, mid);
		mergeSort2(orig_arr, ret_arr, mid+1, end);
		merge(ret_arr, orig_arr, sta, mid, end);
		for (int i = 1; i < 6; i++)std::cout << ret_arr[i] << " ";
		std::cout << "\n";
		for (int i = 1; i < 6; i++)std::cout << orig_arr[i] << " ";
		std::cout << "\n\n";
		merge(orig_arr, ret_arr, sta, mid, end);
		for (int i = 1; i < 6; i++)std::cout << ret_arr[i] << " ";
		std::cout << "\n";
		for (int i = 1; i < 6; i++)std::cout << orig_arr[i] << " ";
		std::cout << "\n\n";
	}
}


int orig[] = { 0, 26,31,18,37,35 };
//int orig[] = { 0, 60,20,10,50,15,30,55 };
//int orig[] = { 0,2,5,1,9,3,8,21,4,11,13,7,22,12,17,6,56,34,26,43,27,26,31,36,41,89,47,19,67,56,77,51,59,42,60 };
int arr_length = sizeof(orig) / sizeof(int);
int* result = new int[arr_length]();
void tmpFunc() {
	//mergePass(orig, order, 8, 4);
	std::cout << "arr_length=" << arr_length << "\n";
	//mergeSort(orig, order, arr_length);
	mergeSort2(orig, result, 1, arr_length - 1);
	for (int i = 1; i < arr_length; i++)std::cout << result[i] << " ";
	delete[] result;
}
