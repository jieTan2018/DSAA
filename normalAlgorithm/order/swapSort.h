#pragma once
#include"generic.h"
/*����������Ԫ�رȽϣ������򽻻���*/
// 1.1 ð�����򣺽�ÿ�ֵ������ð�������ŵ��������λ�á�
int* bubbleSort(int* orig_array, int arr_length) {
	for (int i = 0; i < arr_length - 1; i++) {
		for (int j = 0; j < arr_length - i - 1; j++)  // �� i ��Ԫ�أ�Ҫ�������������Ԫ�رȽϽ������� i+1 => length-1
		{
			if (orig_array[j] > orig_array[j + 1]) {  // ����
				int tmp = orig_array[j];
				orig_array[j] = orig_array[j + 1];
				orig_array[j + 1] = tmp;
			}
		}
	}
	return orig_array;
}
//1.2 ����־��ð������
int* bubbleFlagSort(int* orig_array, int arr_length) {
	bool flag;
	for(int i = 0; i < arr_length - 1; i++) {
		//cout << "i��" << i << endl;
		flag = true;
		for (int j = 0; j < arr_length - 1 - i; j++) {
			if (orig_array[j] > orig_array[j + 1]) {  // ����
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

//2�����������ص㣡��
//2.1��һ�λ��֣���������
int parttion(int* orig_array, int start, int end) {
	int l = start, r = end;  // l: left, r: right
	while (l < r)
	{
		//1. �Ҳ�ɨ��
		while (l < r && orig_array[l] < orig_array[r]) r--;
		if (l < r) {
			int tmp = orig_array[r];
			orig_array[r] = orig_array[l];
			orig_array[l++] = tmp;
		}
		//2. ���ɨ��
		while (l < r && orig_array[l] <= orig_array[r])l++;
		if (l < r) {
			int tmp = orig_array[r];
			orig_array[r--] = orig_array[l];
			orig_array[l] = tmp;
		}
	}
	return l;
}
//2.2�����ţ��Ƚϴ����еȣ��ڼ�¼�ܶ������£����¼�ƶ�����ԶС���۰롢ð�ݵ����򡣣���¼�ƶ������٣�����Ч�ʸߣ�
int* quickSort(int* orig_array, int start, int end) {
	if (start < end) {  // �ݹ��˳�������start >= end
		int povit = parttion(orig_array, start, end);
		quickSort(orig_array, start, povit - 1);
		quickSort(orig_array, povit + 1, end);
	}
	return orig_array;
}
