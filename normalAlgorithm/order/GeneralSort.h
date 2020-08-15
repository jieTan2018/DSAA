#pragma once
// 常用的排序算法实现

struct BNode {  // BucketNode
	int data;  // 元素的值
	BNode* next;  // 后继元素的地址
	BNode(int data, BNode* next = NULL) :data(data), next(next) {}
};
struct BucketQueue {
	BNode* front;  // 始终记录该bucket中的 第一个 元素位置
	BNode* rear;  // 始终记录该bucket中的 最后一个 元素位置
};

class GeneralSort {
private:
	static int array_len;
	int* orig_arr;
	int* dynamicArray(int* orig_array, int new_length = 0);
	inline void swapElements(int &small, int &big) { orig_arr[0] = small; small = big; big = orig_arr[0]; }
	int oncePatition(int sta, int end);  // 快排的“一次划分”，返回轴值
	void heapTop(int sta, int end);  // 堆排的“寻找堆顶”，在左右子树为堆时，来构建完整的堆
	void merge(int* order_arr, int* new_arr, int sta, int mid, int end);  // 归排的“一次归并” | order_arr：原始有序的序列，new_arr：两个原始有序的序列排序后存放的地方
	void mergePass(int* order_arr, int* new_arr, int h);  // 归排的“一轮归并” | order_arr：原始有序的序列，new_arr：两个原始有序的序列排序后存放的地方
	void recursionMerge(int* res_arr, int sta, int end);  // 归排的“递归归并”
	void distribute(int radix, BucketQueue* bucket_queue);  // 基排的“分配”
	void collect(int bucket_nums, BucketQueue* bucket_queue);  // 基排的“收集”
public:
	GeneralSort(int* init_arr, int arr_len);
	~GeneralSort() { delete[] orig_arr; }
	void printArray(int start, int end, int* arr);
	/* 1. 插入排序 */
	void insertSort(int step);  // 1.1 直接插入排序
	void shellSort(){ for (int d = array_len / 2; d > 0; d /= 2)insertSort(d); }  // 1.2 希尔排序
	/* 2. 交换排序 */
	void bubbleSort();  // 2.1 冒泡排序
	void quickSort(int sta, int end);  // 2.2 快速排序
	/* 3. 选择排序 */
	void simpleSelectSort();  // 3.1 简单选择排序
	void heapSort();  // 3.2 堆排序
	/* 4. 归并排序 */
	void mergeSort();  // 4.1 非递归实现
	void recursionMergeSort();  // 4.2 递归实现
	/* 5 分配排序 */
	void bucketSort(int bucket_nums);  // 5.1 桶式排序
	void radixSort(int max_value);  // 5.2 基数排序
};

int GeneralSort::array_len = 0;

GeneralSort::GeneralSort(int* init_arr, int arr_len){
	// 构造新的数组，使得数据的操作都在下标 1 ~ arr_len 上进行，便于理解与操作。
 	array_len = arr_len + 1;
	orig_arr = dynamicArray(init_arr, array_len);
}

int* GeneralSort::dynamicArray(int* init_array, int new_length) {
	// 动态申请一个可带 哨兵 的数组。（用完后记得 delete，避免内存泄漏）
	int* new_array = new int[new_length]();
	if (init_array != NULL) {
		for (int i = 1; i < new_length; i++) new_array[i] = init_array[i - 1];
	}
	return new_array;
}

void GeneralSort::printArray(int start = 1, int end = -1, int* arr = NULL) {
	if (arr == NULL) arr = orig_arr;
	if (end == -1)end = array_len;
	for (int i = start; i < end; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void GeneralSort::insertSort(int step=1) {
	for (int i = 1 + step; i < array_len; i++) {
		int j = i - step;  // 首先和前step位元素比较
		orig_arr[0] = orig_arr[i];
		for (; orig_arr[0] < orig_arr[j]; j -= step)orig_arr[j + step] = orig_arr[j];  // 元素后移
		orig_arr[j + step] = orig_arr[0];
	}
}

void GeneralSort::bubbleSort() {
	bool end_flag;
	for (int i = 1; i < array_len; i++) {
		end_flag = true;
		for (int j = 1; j < array_len - i; j++) {
			if (orig_arr[j] > orig_arr[j + 1]) {
				swapElements(orig_arr[j + 1], orig_arr[j]);
				end_flag = false;
			}
		}
		if (end_flag)break;
	}
}

int GeneralSort::oncePatition(int sta, int end) {
	int l = sta, r = end;
	while (l < r)
	{
		//1. 右侧扫描
		while (l < r && orig_arr[l] < orig_arr[r])r--;
		if (l < r)swapElements(orig_arr[l++], orig_arr[r]);
		//2. 左侧扫描
		while (l < r && orig_arr[r] > orig_arr[l])l++;
		if (l < r)swapElements(orig_arr[r--], orig_arr[l]);
	}
	return l;
}

void GeneralSort::quickSort(int sta = 1, int end = array_len - 1) {
	if (sta < end) {
		int povit = oncePatition(sta, end);
		quickSort(sta, povit - 1);  // 左子序列继续快排
		quickSort(povit + 1, end);  // 右子序列继续快排
	}
}

void GeneralSort::simpleSelectSort() {
	int min_idx;
	for (int i = 1; i < array_len; i++) {
		min_idx = i;
		for (int j = i + 1; j < array_len; j++) {
			if (orig_arr[min_idx] > orig_arr[j]) min_idx = j;
		}
		if (min_idx != i) swapElements(orig_arr[min_idx], orig_arr[i]);
	}
}

void GeneralSort::heapTop(int sta, int end) {
	int i = sta, j = 2 * i;
	while (j <= end)  // j=end时，结点只有左孩子
	{
		if (j < end && orig_arr[j] < orig_arr[j + 1])++j;  // j < end 确保结点右孩子存在
		if (orig_arr[i] > orig_arr[j]) break;
		else
		{
			swapElements(orig_arr[i], orig_arr[j]);
			i = j; j = 2 * i;
		}
	}
}

void GeneralSort::heapSort() {
	int elem_nums = array_len - 1;
	for (int i = elem_nums / 2; i > 0; i--)heapTop(i, elem_nums);  // 初始建堆
	for (int i = 1; i < elem_nums; i++) {  
		swapElements(orig_arr[1], orig_arr[array_len - i]);  // 移除堆顶
		heapTop(1, elem_nums - i);  // 重建堆
	}
}

void GeneralSort::merge(int* order_arr, int* new_arr, int sta, int mid, int end) {
	int i = sta, j = mid + 1, k=sta;
	while (i <= mid && j <= end)
	{
		if (order_arr[i] <= order_arr[j])new_arr[k++] = order_arr[i++];
		else new_arr[k++] = order_arr[j++];
	}
	if (i <= mid)while (i <= mid)new_arr[k++] = order_arr[i++];
	else while (j <= end)new_arr[k++] = order_arr[j++];
}

void GeneralSort::mergePass(int* order_arr, int* new_arr, int h) {
	int step = 2 * h;
	int sta = 1;
	while (sta <= array_len - step - 1)
	{
		merge(order_arr, new_arr, sta, sta + h - 1, sta + step - 1);
		sta += step;
	}
	if (sta < array_len - h)merge(order_arr, new_arr, sta, sta + h - 1, array_len - 1);
	else while (sta < array_len)new_arr[sta] = order_arr[sta++];
}

void GeneralSort::mergeSort() {
	int h = 1;
	int* res_arr = new int[array_len];
	while (h < array_len)
	{
		mergePass(orig_arr, res_arr, h);
		h *= 2;
		mergePass(res_arr, orig_arr, h);  // 将排序后的结果替换orig中的原记录
		h *= 2;
	}
	delete[] res_arr;
}

void GeneralSort::recursionMerge(int* res_arr, int sta, int end) {
	if (sta == end) res_arr[sta] = orig_arr[sta];
	else
	{
		int mid = (sta + end) / 2;
		recursionMerge(res_arr, sta, mid);
		recursionMerge(res_arr, mid + 1, end);
		merge(orig_arr, res_arr, sta, mid, end);
		while (sta <= end)orig_arr[sta] = res_arr[sta++];  // 重点！
	}
}

void GeneralSort::recursionMergeSort() {
	int* res_arr = new int[array_len];
	recursionMerge(res_arr, 1, array_len - 1);
	delete[] res_arr;
}

void GeneralSort::bucketSort(int b_nums) {
	int o_idx = 0;  // orig_arr的下标
	int* bucket_arr = new int[b_nums]();  // 构建桶
	// 分配（distribute）：用桶的下标来记录orig_arr的元素值，桶的值记录orig_arr的元素出现的次数
	for (int i = 1; i < array_len; i++) ++bucket_arr[orig_arr[i]];  // orig_arr[i]作bucket_arr的下标
	// 收集（collect）：顺序收集桶中的元素，重复的则占连续的几个位置
	for (int i = 0; i < b_nums; i++) {
		if (bucket_arr[i] > 0) for (int j = 0; j < bucket_arr[i]; j++) orig_arr[++o_idx] = i;
	}
	// 回收指针
	delete[] bucket_arr;
}

void GeneralSort::distribute(int radix, BucketQueue* b_queue) {
	int b_idx;  //  bucket的下标
	for (int i = 1; i < array_len; i++) {
		b_idx = (orig_arr[i] / radix) % 10;  // 根据基数，取出某个元素对应位置的元素（个、十、百等位置）
		BNode* new_node = new BNode(orig_arr[i]);
		if (b_queue[b_idx].front != NULL) {  // 入队操作
			b_queue[b_idx].rear->next = new_node;
			b_queue[b_idx].rear = b_queue[b_idx].rear->next;
		}
		else b_queue[b_idx].front = b_queue[b_idx].rear = new_node;
	}
}

void GeneralSort::collect(int bucket_nums, BucketQueue* b_queue) {
	int o_idx = 0;  // orig_arr的下标
	for (int i = 0; i < bucket_nums; i++) {
		if (b_queue[i].front != NULL)
			while (b_queue[i].front != NULL)
			{  // 出队操作
				orig_arr[++o_idx] = b_queue[i].front->data;
				b_queue[i].front = b_queue[i].front->next;
			}
	}
}

void GeneralSort::radixSort(int max_val) {
	const int base_num = 10;
	int radix;  // 基数
	int count = 1;  // 记录max_val的位数，初始为个位
	for (int quotien = max_val / base_num; quotien > 0; quotien /= base_num)++count;
	// 按最大数拥有的位数来进行分配、收集
	for (int k = 0; k < count; k++) {
		BucketQueue* b_queue = new BucketQueue[base_num]();
		radix = (int)pow(base_num, k);
		distribute(radix, b_queue);  // 分配
		collect(base_num, b_queue);  // 收集
		delete[] b_queue;
	}
}
