#pragma once
/*选择排序：每轮选出无序区中最小的元素，放入到有序区中。==> 元素位置移动次数少。*/
//1、简单选择排序：每轮比较，最多有一次元素交换（即和该轮首位元素的交换）。
int* simpleSelectSort(int* orig_array, int arr_length) {
	int tmp, index;
	for (int i = 0; i < arr_length - 1; i++) {
		index = i;
		for (int j = i + 1; j < arr_length; j++) {
			if (orig_array[j] < orig_array[index])index = j;
		}
		if (i != index) {
			tmp = orig_array[index];
			orig_array[index] = orig_array[i];
			orig_array[i] = tmp;
		}
	}
	return orig_array;
}

//2、堆排序：解决简单排序比较次数过多的问题。
//2.1 堆顶：在左右子树均的情况下，选出堆顶元素，并排在首位。
void heapTop(int* orig_array, int start, int seq_length) {
	int i = start, j = 2 * i;
	while (j <= seq_length)  // 退出时，表明已到达叶子位置
	{
		// i. 找出左右子孩子中最大的
		if (j < seq_length && orig_array[j] < orig_array[++j]) {}
		// ii. 如果根大于大孩子，则退出
		if (orig_array[i] > orig_array[j]) break;
		// iii. 与大孩子作位置交换
		else
		{
			// 交换
			orig_array[0] = orig_array[i];
			orig_array[i] = orig_array[j];
			orig_array[j] = orig_array[0];
			// 下标相应变化
			i = j; 
			j = 2 * i;
		}
	}
}
//2.2 堆排序
int* heapSort(int* orig_array, int arr_length) {
	int last_idx;
	// i. 初始化构建堆结构
	for (int i = arr_length / 2; i > 0; i--) {  // 叶子结点从 n/2 + 1 处开始出现。由于叶子都可看成堆，所以只需对1~（n/2）的结点构建堆，即可完成整个序列的堆结构。
		heapTop(orig_array, i, arr_length);
	}
	// ii. 选出每轮的堆顶元素
	for (int i = 1; i < arr_length; i++) {
		last_idx = arr_length - i + 1; 
		//  交换：将堆顶元素与堆尾元素交换（也叫将堆顶元素放入有序区）
		orig_array[0] = orig_array[1];
		orig_array[1] = orig_array[last_idx];
		orig_array[last_idx] = orig_array[0];
		// 对剩下的元素重新建堆：由于只有原堆顶元素交换了，左右子树还是堆，故每轮只用调用一次heapTop
		heapTop(orig_array, 1, arr_length - i);
	}
	return orig_array;
}