#include<iostream>
using namespace std;

/*�˲��ֿ�д��.h�ļ���*/
template<class DataType>
struct Node
{
	DataType data;
	Node<DataType>* prior, *next;
};

template<class DataType>
class LinkList {
private:
	Node<DataType>* first;
public:
	LinkList();
	LinkList(DataType arr[], int length); 
	~LinkList();
	int getLength();  // ��ȡ������
	int getIndex(DataType data);  //����ֵ����λ��
	void insertData(int i, DataType data, bool is_add=false);  // �ڵ�i��λ���ϣ���������
	DataType deleteData(int i);  //ɾ����i��λ���ϵ�����
	void printList();  //��ӡ����

	Node<DataType>* getNode(int i);  //����index���ؽ��
	inline Node<DataType>* addNode(Node<DataType>* prior_node, DataType data);  //���ӽ��
};

template<class DataType>
LinkList<DataType>::LinkList() {  // Ĭ�ϴ���һ��������
	first = new Node<DataType>;
	first->data = 0;  // ��ͷ�ڵ����������ĳ���
	first->prior = first;
	first->next = first;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType arr[], int length) {  //�������ʼ��һ������
	// ͷָ��ָ���һ��Ԫ��
	first = new Node<DataType>;
	first->data = 0;  // ��ͷ�ڵ����������ĳ���
	first->prior = first;
	first->next = first;
	// ����Ԫ�صĸ�ֵ || ��Ԫ��β������
	Node<DataType>* last = first;  // ����һ��βָ�룬ָ�����һ��Ԫ�ء�| �տ�ʼ��βָ���ͷָ��λ���غϣ�
	for (int i = 0; i < length; i++) {  // ��ÿ������β������Ԫ�ء�Ԫ����������=>
		last = addNode(last, arr[i]);  // βָ��ָ������Ԫ�ء�
	}
}

template<class DataType>
LinkList<DataType>::~LinkList() {  // ɾ������Ԫ��
	Node<DataType>* cursor = first;
	do
	{
		Node<DataType>* del_node = cursor;
		cout << "del_node data: " << del_node->data << ", " << del_node->next << endl;
		cursor = cursor->next;  //  ͷָ��ÿ�ƶ�����һ�����󣬾�ɾ��ǰ���Ǹ���㡣
		delete del_node;
	} while (cursor != first);
}

template<class DataType>
int LinkList<DataType>::getLength() {  // ������ͷ���洢���ȵķ�ʽ������Ҫ�ڴ˴����������ʺ����ݽ�С��������
	return first->data;
}

template<class DataType>
Node<DataType>* LinkList<DataType>::getNode(int i) {
	if (i<1 || i>first->data) throw "Index out of range! index=" + i;
	Node<DataType>* cursor = first;
	int count = 0;
	if (i > first->data / 2) { // ��β����ǰ����
		count = first->data + 1;
		do
		{
			//cout << "end count" << count << endl;
			cursor = cursor->prior;
			count--;
		} while (count > i && cursor != first);
	}
	else
	{ // ��ͷ��������
		do
		{
			//cout << "start count" << count << endl;
			cursor = cursor->next;
			count++;
		} while (count < i && cursor != first);
	}
	if (cursor == first) throw "Index out of range! index=" + i;
	return cursor;
}

template<class DataType>
Node<DataType>* LinkList<DataType>::addNode(Node<DataType>* prior_node, DataType data) {
	Node<DataType>* node = new Node<DataType>;  // ������Ľ��
	node->data = data;
	node->prior = prior_node;
	node->next = prior_node->next;
	prior_node->next->prior = node;
	prior_node->next = node;
	first->data++;

	return node;
}

template<class DataType>
int LinkList<DataType>::getIndex(DataType data) { // �Աȸ���indexѰ�ҽ�㣬��֪��Ϊʲô����ֵ�ҽ��Ч��Ҫ�͵ö��ˣ�����ֵ��ֻ�ܴ�һͷ�����ߣ���
	Node<DataType>* cursor = first;
	int count = 0;
	do
	{
		cursor = cursor->next;
		count++;
	} while (cursor != first && cursor->data != data);

	if (cursor == first) throw "Can't find value is: " + data;
	return count;
}

template<class DataType>
void LinkList<DataType>::insertData(int i, DataType data, bool is_add) {
	Node<DataType>* cursor = getNode(i);
	if (is_add) addNode(cursor, data);  // is_add=true�� �� i ��λ���� add ��㣨�ڵ� i+1 �����֮�� insert ��㣩��
	else addNode(cursor->prior, data);  //  is_add=false���ڵ� i ��λ���� insert ��㣨�ڵ� i-1 �����֮�� add ��㣩��
}

template<class DataType>
DataType LinkList<DataType>::deleteData(int i) {
	Node<DataType>* cursor = getNode(i);
	DataType node_data = cursor->data;
	cursor->prior->next = cursor->next;
	cursor->next->prior = cursor->prior;
	delete cursor;
	first->data--;
	return node_data;
}

template<class DataType>
void LinkList<DataType>::printList() {
	Node<DataType>* cursor = first->next;
	int count = 0;
	do
	{
		cout << "==> " << cursor->data << ", addr= " << cursor << endl;
		cursor = cursor->next;
		count++;
	} while (cursor != first); 
}

int main() {
	int arr[] = { 11,22,33,44,55,66,77,88,99 };
	//int arr[] = { 11,22,33 };
	LinkList<int> list(arr, 9);
	list.printList();
	//cout << endl;
	//cout << "list's length is: " << list.getLength() << endl;
	//cout << endl;
	//cout << "list's index is: " << list.getIndex(55) << endl;
	cout << endl;
	list.insertData(1, 111);  // insert
	list.insertData(10, 222, true);  // add
	list.printList();
	//cout << endl;
	//cout << "list's delete is: " << list.deleteData(4) << endl;
	//list.printList();
	//cout << endl;
	//cout << "list's Node is: " << list.getNode(7)->data << endl;
	//cout << endl;
}