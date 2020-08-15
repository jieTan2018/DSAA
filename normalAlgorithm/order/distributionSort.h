#pragma once
#include<cmath>
// 分配式排序
struct QueueNode { int front, rear; };
// 1、桶式排序
void distribute(int* orig, int n, QueueNode* queue) {
	int q_idx;
	for (int i = 0; i < n; i++) {
		q_idx = orig[i];
		if (queue[q_idx].front != queue[q_idx].rear) {
			++queue[q_idx].rear;
		}
		else
		{
			queue[q_idx].rear += 2;  // 有一个元素时将rear置1
		}
		std::cout << "q_idx:" << q_idx << ", rear: " << queue[q_idx].rear << "\n";
	}
}

void collect(int* orig, int n, QueueNode* queue, int m) {
	int o_idx = -1;
	for (int i = 0; i < m; i++) {
		std::cout << "i:" << i << ", o_idx:" << o_idx << ", rear:" << queue[i].rear << "\n";
		if (queue[i].rear > 0) {
			for (int j = 0; j < queue[i].rear; j++) {
				orig[++o_idx] = i;
			}
		}
	}
}

void bucketSort(int* orig, int n, int m) {
	QueueNode* queue = new QueueNode[m];
	for (int i = 0; i < m; i++) queue[i].front = queue[i].rear = -1;
	distribute(orig, n, queue);
	collect(orig, n, queue, m);
	delete[] queue;
}

// 2、基数排序：某个桶中的元素值有多个，所以需要借助queue来存储元素（二维数组浪费地址空间，故未采用）
struct QNode {
	int data;
	QNode* next;
	QNode(int data, QNode* next = NULL) :data(data), next(next) {}
};
struct Queue {
	QNode* front;
	QNode* node;
};

void radixSort(int* orig, int n, int max_value) {
	const int base_num = 10;
	int count = 1;
	for(int quotien = max_value / base_num; quotien>0; quotien /= base_num)++count;
	// 按最大数拥有的位数来进行分配、收集
	int radix = 1;  // 基数
	for (int k = 0; k < count; k++) {
		Queue* bucket = new Queue[base_num]();
		radix = (int)pow(10, k);
		// 分配
		int b_idx;
		for (int i = 0; i < n; i++) {
			b_idx = (orig[i] / radix) % 10;
			if (bucket[b_idx].front != NULL) {
				QNode* new_node = new QNode(orig[i]);
				bucket[b_idx].node->next = new_node;
				bucket[b_idx].node = bucket[b_idx].node->next;
			}
			else bucket[b_idx].front = bucket[b_idx].node = new QNode(orig[i]);
		}
		// 收集
		int o_idx = -1;
		for (int i = 0; i < base_num; i++) {
			if (bucket[i].front != NULL) {
				while (bucket[i].front != NULL)
				{
					orig[++o_idx] = bucket[i].front->data;
					bucket[i].front = bucket[i].front->next;
				}
			}
		}
		// 中间过程打印
		for (int i = 0; i < n; i++) {
			std::cout << orig[i] << " ";
		}
		std::cout << "\n";
		delete[] bucket;
	}
}

void myMain() {
	std::cout << "my main run!\n";
	//int N = 14;
	/*int init_arr[] = { 3,5,3,1,5,6,3,8,12, 3,5,1,7,8 };*/
	int init_arr[] = { 61,98,12,15,20,24,31,23,35,35,123,34,12,55,678,6,33,56,78,29,10,435,654,78 };
	int N = sizeof(init_arr) / sizeof(int);
	//bucketSort(init_arr, N, M);
	radixSort(init_arr, N, 678);
	/*for (int i = 0; i < N; i++) {
		std::cout << init_arr[i] << " ";
	}*/
}