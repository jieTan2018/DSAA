#include <iostream>
#include"binary_search.h"
#include"biSortTree.h"
using namespace std;

int main()
{
	//int seq_arr[] = { 1,2,4,6,7,9,14,16,19,25,31,33,36,42 };
	int seq_arr[] = { 7,1,5,9,8,10,3 };
	int arr_length = sizeof(seq_arr) / sizeof(int);
	cout << "len:" << arr_length << endl;
	/*cout << "折半查找：\n";
	int ret = binarySearch(seq_arr, 11, 0, arr_length-1);
	cout << "ret=" << ret << endl;
	int ret_2 = binary_search(seq_arr, 8, arr_length);
	cout << "ret_2=" << ret_2 << endl;
	cout << "********************* \n";*/
	cout << "二叉排序树：\n";
	BiSortTree bst(seq_arr, arr_length);
	cout << "node:" << bst.search(5) << endl;
	bst.remove(4);
	//struct PTRNode
	//{
	//	int data;
	//	PTRNode() {
	//		data = 99;
	//	}
	//};
	//PTRNode pn;
	////cout << pn.data;
	//PTRNode* ptr = &pn;
	//PTRNode** pptr = &ptr;
	//cout << "&pn:" << &pn << ", data:" << pn.data << endl;
	//cout << "ptr:" << ptr << ", &ptr:" << &ptr << ", data:" << (*ptr).data << endl;
	//cout << "pptr:" << pptr<<", &pptr:"<<&pptr<<", *pptr:"<<*pptr<<", &**pptr(&pn):"<<&(**pptr) << ", data:" << (**pptr).data << endl;
	///*
	//** 指针->属性：“->”表示取指针所指的内容，并访问内容的属性。
	//** 如 ptr->data ："ptr->" 等价于 "&pn-> => pn."。所以 "ptr->data" => "pn.data"。
	//*/
	//cout << "ptr data: " << ptr->data << ", pptr data:" << (*pptr)->data << endl;
	//cout << "&pn data:" << (&pn)->data << endl;
}
