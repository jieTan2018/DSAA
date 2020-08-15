#pragma once
// �۰���ң������������

// �ݹ�ʵ��
int binarySearch(int* seqArray, int data, int start, int end) {
	if (start > end) return -1; // û�鵽����-1
	else
	{
		int mid = (start + end) / 2;
		if (data > seqArray[mid]) return binarySearch(seqArray, data, mid + 1, end);
		else
		{
			if (data == seqArray[mid])return mid;
			return binarySearch(seqArray, data, start, mid - 1);
		}
	}
}

// �ǵݹ�ʵ�֣��Ƽ�ʹ��
int binary_search(int* seqArray, int data, int length) {
	int start = 0, end = length - 1;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (data > seqArray[mid])start = mid + 1;
		else
		{
			if (data == seqArray[mid])return mid;
			end = mid - 1;
		}
	}
	return -1;
}