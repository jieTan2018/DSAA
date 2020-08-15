#pragma once
// ���õ������㷨ʵ��

struct BNode {  // BucketNode
	int data;  // Ԫ�ص�ֵ
	BNode* next;  // ���Ԫ�صĵ�ַ
	BNode(int data, BNode* next = NULL) :data(data), next(next) {}
};
struct BucketQueue {
	BNode* front;  // ʼ�ռ�¼��bucket�е� ��һ�� Ԫ��λ��
	BNode* rear;  // ʼ�ռ�¼��bucket�е� ���һ�� Ԫ��λ��
};

class GeneralSort {
private:
	static int array_len;
	int* orig_arr;
	int* dynamicArray(int* orig_array, int new_length = 0);
	inline void swapElements(int &small, int &big) { orig_arr[0] = small; small = big; big = orig_arr[0]; }
	int oncePatition(int sta, int end);  // ���ŵġ�һ�λ��֡���������ֵ
	void heapTop(int sta, int end);  // ���ŵġ�Ѱ�ҶѶ���������������Ϊ��ʱ�������������Ķ�
	void merge(int* order_arr, int* new_arr, int sta, int mid, int end);  // ���ŵġ�һ�ι鲢�� | order_arr��ԭʼ��������У�new_arr������ԭʼ���������������ŵĵط�
	void mergePass(int* order_arr, int* new_arr, int h);  // ���ŵġ�һ�ֹ鲢�� | order_arr��ԭʼ��������У�new_arr������ԭʼ���������������ŵĵط�
	void recursionMerge(int* res_arr, int sta, int end);  // ���ŵġ��ݹ�鲢��
	void distribute(int radix, BucketQueue* bucket_queue);  // ���ŵġ����䡱
	void collect(int bucket_nums, BucketQueue* bucket_queue);  // ���ŵġ��ռ���
public:
	GeneralSort(int* init_arr, int arr_len);
	~GeneralSort() { delete[] orig_arr; }
	void printArray(int start, int end, int* arr);
	/* 1. �������� */
	void insertSort(int step);  // 1.1 ֱ�Ӳ�������
	void shellSort(){ for (int d = array_len / 2; d > 0; d /= 2)insertSort(d); }  // 1.2 ϣ������
	/* 2. �������� */
	void bubbleSort();  // 2.1 ð������
	void quickSort(int sta, int end);  // 2.2 ��������
	/* 3. ѡ������ */
	void simpleSelectSort();  // 3.1 ��ѡ������
	void heapSort();  // 3.2 ������
	/* 4. �鲢���� */
	void mergeSort();  // 4.1 �ǵݹ�ʵ��
	void recursionMergeSort();  // 4.2 �ݹ�ʵ��
	/* 5 �������� */
	void bucketSort(int bucket_nums);  // 5.1 Ͱʽ����
	void radixSort(int max_value);  // 5.2 ��������
};

int GeneralSort::array_len = 0;

GeneralSort::GeneralSort(int* init_arr, int arr_len){
	// �����µ����飬ʹ�����ݵĲ��������±� 1 ~ arr_len �Ͻ��У���������������
 	array_len = arr_len + 1;
	orig_arr = dynamicArray(init_arr, array_len);
}

int* GeneralSort::dynamicArray(int* init_array, int new_length) {
	// ��̬����һ���ɴ� �ڱ� �����顣�������ǵ� delete�������ڴ�й©��
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
		int j = i - step;  // ���Ⱥ�ǰstepλԪ�رȽ�
		orig_arr[0] = orig_arr[i];
		for (; orig_arr[0] < orig_arr[j]; j -= step)orig_arr[j + step] = orig_arr[j];  // Ԫ�غ���
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
		//1. �Ҳ�ɨ��
		while (l < r && orig_arr[l] < orig_arr[r])r--;
		if (l < r)swapElements(orig_arr[l++], orig_arr[r]);
		//2. ���ɨ��
		while (l < r && orig_arr[r] > orig_arr[l])l++;
		if (l < r)swapElements(orig_arr[r--], orig_arr[l]);
	}
	return l;
}

void GeneralSort::quickSort(int sta = 1, int end = array_len - 1) {
	if (sta < end) {
		int povit = oncePatition(sta, end);
		quickSort(sta, povit - 1);  // �������м�������
		quickSort(povit + 1, end);  // �������м�������
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
	while (j <= end)  // j=endʱ�����ֻ������
	{
		if (j < end && orig_arr[j] < orig_arr[j + 1])++j;  // j < end ȷ������Һ��Ӵ���
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
	for (int i = elem_nums / 2; i > 0; i--)heapTop(i, elem_nums);  // ��ʼ����
	for (int i = 1; i < elem_nums; i++) {  
		swapElements(orig_arr[1], orig_arr[array_len - i]);  // �Ƴ��Ѷ�
		heapTop(1, elem_nums - i);  // �ؽ���
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
		mergePass(res_arr, orig_arr, h);  // �������Ľ���滻orig�е�ԭ��¼
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
		while (sta <= end)orig_arr[sta] = res_arr[sta++];  // �ص㣡
	}
}

void GeneralSort::recursionMergeSort() {
	int* res_arr = new int[array_len];
	recursionMerge(res_arr, 1, array_len - 1);
	delete[] res_arr;
}

void GeneralSort::bucketSort(int b_nums) {
	int o_idx = 0;  // orig_arr���±�
	int* bucket_arr = new int[b_nums]();  // ����Ͱ
	// ���䣨distribute������Ͱ���±�����¼orig_arr��Ԫ��ֵ��Ͱ��ֵ��¼orig_arr��Ԫ�س��ֵĴ���
	for (int i = 1; i < array_len; i++) ++bucket_arr[orig_arr[i]];  // orig_arr[i]��bucket_arr���±�
	// �ռ���collect����˳���ռ�Ͱ�е�Ԫ�أ��ظ�����ռ�����ļ���λ��
	for (int i = 0; i < b_nums; i++) {
		if (bucket_arr[i] > 0) for (int j = 0; j < bucket_arr[i]; j++) orig_arr[++o_idx] = i;
	}
	// ����ָ��
	delete[] bucket_arr;
}

void GeneralSort::distribute(int radix, BucketQueue* b_queue) {
	int b_idx;  //  bucket���±�
	for (int i = 1; i < array_len; i++) {
		b_idx = (orig_arr[i] / radix) % 10;  // ���ݻ�����ȡ��ĳ��Ԫ�ض�Ӧλ�õ�Ԫ�أ�����ʮ���ٵ�λ�ã�
		BNode* new_node = new BNode(orig_arr[i]);
		if (b_queue[b_idx].front != NULL) {  // ��Ӳ���
			b_queue[b_idx].rear->next = new_node;
			b_queue[b_idx].rear = b_queue[b_idx].rear->next;
		}
		else b_queue[b_idx].front = b_queue[b_idx].rear = new_node;
	}
}

void GeneralSort::collect(int bucket_nums, BucketQueue* b_queue) {
	int o_idx = 0;  // orig_arr���±�
	for (int i = 0; i < bucket_nums; i++) {
		if (b_queue[i].front != NULL)
			while (b_queue[i].front != NULL)
			{  // ���Ӳ���
				orig_arr[++o_idx] = b_queue[i].front->data;
				b_queue[i].front = b_queue[i].front->next;
			}
	}
}

void GeneralSort::radixSort(int max_val) {
	const int base_num = 10;
	int radix;  // ����
	int count = 1;  // ��¼max_val��λ������ʼΪ��λ
	for (int quotien = max_val / base_num; quotien > 0; quotien /= base_num)++count;
	// �������ӵ�е�λ�������з��䡢�ռ�
	for (int k = 0; k < count; k++) {
		BucketQueue* b_queue = new BucketQueue[base_num]();
		radix = (int)pow(base_num, k);
		distribute(radix, b_queue);  // ����
		collect(base_num, b_queue);  // �ռ�
		delete[] b_queue;
	}
}
