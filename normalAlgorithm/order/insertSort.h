#pragma once
using namespace std;
/*��������*/
// 1��ֱ�Ӳ�������
int* insertSort(int* orig_array, int arr_length, int step=1) {
	for (int i = step + 1; i < arr_length; i++) {  // �Ѽ����step���Ϊ����λ1�����͸�ʵ�������ŵ����е���������ˡ�
		orig_array[0] = orig_array[i];
		int j;
		for (j = i - step; orig_array[0] < orig_array[j]; j -= step) {
			orig_array[j + step] = orig_array[j];  // ���ֵ������
		}
		orig_array[j + step] = orig_array[0];  // �Ƚϵ���һ��ֵʱ��[0]>[j]�ˣ���ʱ j-- �ˣ�����ŵ�λ�ñ��� j+1 �ˡ�
	}

	return orig_array;
}  

// 2��ϣ������
int* shellSort(int* orig_array, int arr_length) {
	for (int d = arr_length / 2; d > 0; d /= 2) {
		insertSort(orig_array, arr_length, d); 
	}
	return orig_array;
}