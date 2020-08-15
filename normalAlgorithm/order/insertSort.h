#pragma once
using namespace std;
/*插入排序*/
// 1、直接插入排序
int* insertSort(int* orig_array, int arr_length, int step=1) {
	for (int i = step + 1; i < arr_length; i++) {  // 把间隔的step理解为“单位1”，就跟实际相连着的序列的排序情况了。
		orig_array[0] = orig_array[i];
		int j;
		for (j = i - step; orig_array[0] < orig_array[j]; j -= step) {
			orig_array[j + step] = orig_array[j];  // 大的值都后移
		}
		orig_array[j + step] = orig_array[0];  // 比较到下一个值时，[0]>[j]了，此时 j-- 了，则空着的位置便是 j+1 了。
	}

	return orig_array;
}  

// 2、希尔排序
int* shellSort(int* orig_array, int arr_length) {
	for (int d = arr_length / 2; d > 0; d /= 2) {
		insertSort(orig_array, arr_length, d); 
	}
	return orig_array;
}