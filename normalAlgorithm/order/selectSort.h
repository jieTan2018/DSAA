#pragma once
/*ѡ������ÿ��ѡ������������С��Ԫ�أ����뵽�������С�==> Ԫ��λ���ƶ������١�*/
//1����ѡ������ÿ�ֱȽϣ������һ��Ԫ�ؽ��������͸�����λԪ�صĽ�������
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

//2�������򣺽��������Ƚϴ�����������⡣
//2.1 �Ѷ���������������������£�ѡ���Ѷ�Ԫ�أ���������λ��
void heapTop(int* orig_array, int start, int seq_length) {
	int i = start, j = 2 * i;
	while (j <= seq_length)  // �˳�ʱ�������ѵ���Ҷ��λ��
	{
		// i. �ҳ������Ӻ���������
		if (j < seq_length && orig_array[j] < orig_array[++j]) {}
		// ii. ��������ڴ��ӣ����˳�
		if (orig_array[i] > orig_array[j]) break;
		// iii. �������λ�ý���
		else
		{
			// ����
			orig_array[0] = orig_array[i];
			orig_array[i] = orig_array[j];
			orig_array[j] = orig_array[0];
			// �±���Ӧ�仯
			i = j; 
			j = 2 * i;
		}
	}
}
//2.2 ������
int* heapSort(int* orig_array, int arr_length) {
	int last_idx;
	// i. ��ʼ�������ѽṹ
	for (int i = arr_length / 2; i > 0; i--) {  // Ҷ�ӽ��� n/2 + 1 ����ʼ���֡�����Ҷ�Ӷ��ɿ��ɶѣ�����ֻ���1~��n/2���Ľ�㹹���ѣ���������������еĶѽṹ��
		heapTop(orig_array, i, arr_length);
	}
	// ii. ѡ��ÿ�ֵĶѶ�Ԫ��
	for (int i = 1; i < arr_length; i++) {
		last_idx = arr_length - i + 1; 
		//  ���������Ѷ�Ԫ�����βԪ�ؽ�����Ҳ�н��Ѷ�Ԫ�ط�����������
		orig_array[0] = orig_array[1];
		orig_array[1] = orig_array[last_idx];
		orig_array[last_idx] = orig_array[0];
		// ��ʣ�µ�Ԫ�����½��ѣ�����ֻ��ԭ�Ѷ�Ԫ�ؽ����ˣ������������Ƕѣ���ÿ��ֻ�õ���һ��heapTop
		heapTop(orig_array, 1, arr_length - i);
	}
	return orig_array;
}