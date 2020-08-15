#pragma once
template<class DataType>
inline DataType* dynamicArray(DataType* orig_array, int new_length=0) {
	// 动态申请一个可带 哨兵 的数组。（用完后记得 delete，避免内存泄漏）
	DataType* new_array = new DataType[new_length]();
	if (orig_array != NULL) {
		for (int i = 1; i < new_length; i++) new_array[i] = orig_array[i - 1];
	}
	return new_array;
}

template<class DataType>
inline void printArray(DataType* orig_array, int arr_length, int start = -1, int end = -1) {
	if (start == -1)start = 0;
	if (end == -1)end = arr_length;
	for (int i = start; i < end; i++) {
		std::cout << orig_array[i] << " ";
	}
	std::cout << "\n";
}