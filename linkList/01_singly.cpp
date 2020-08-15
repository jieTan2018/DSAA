#include<iostream>
using namespace std;

/*�˲��ֿ�д��.h�ļ���*/
template<class DataType>
struct Node
{
	DataType data;
	Node<DataType>* next;
};

template<class DataType>
class LinkList {
private:
	Node<DataType>* first;
public:
	LinkList();
	//  ��ǰ���д�ͷ�������д�����ű�����insertEnd������ɾ����ͷ�巨����ʱinsertEndֻ��Ϊ��չʾĬ�ϴ������Ĺ��캯����д�����ѣ�
	LinkList(DataType arr[], int length, bool insertEnd=true);  // �˴�����Ĭ��ֵ�������ʵ��ʱ�����Ͳ����ڸ�Ĭ��ֵ�ˡ�
	~LinkList();
	int getLength();  // ��ȡ������
	DataType getValue(int i);  //����index����ֵ
	int getIndex(DataType data);  //����ֵ����λ��
	void insertData(int i, DataType data);  // �ڵ�i��λ���ϣ���������
	DataType deleteData(int i);  //ɾ����i��λ���ϵ�����
	void printList();  //��ӡ����
};

template<class DataType>
LinkList<DataType>::LinkList() {  // Ĭ�ϴ���һ��������
	first = new Node<DataType>;
	first->data = 0;  // ��ͷ�ڵ����������ĳ���
	first->next = NULL;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType arr[], int length, bool insertEnd) {  //�������ʼ��һ������ | �˴� insertEnd�����ٸ�Ĭ��ֵ�ˣ�
	// ͷָ��ָ���һ��Ԫ��
	first = new Node<DataType>;
	//first->data = 0;  // ��ͷ�ڵ����������ĳ���
	first->next = NULL;
	// ����Ԫ�صĸ�ֵ || ��Ԫ��β������
	Node<DataType>* last = first;  // ����һ��βָ�룬ָ�����һ��Ԫ�ء�| �տ�ʼ��βָ���ͷָ��λ���غϣ�
	for (int i = 0; i < length; i++) {  // ��ÿ������β������Ԫ�ء�Ԫ����������=>
		Node<DataType>* node = new Node<DataType>;  // ������Ľ��
		node->data = arr[i];
		last->next = node;  // ��ǰһ��Ԫ�ص�nextָ��Ҫ�����Ԫ�ء�
		last = node;  // βָ��֪�������Ԫ�ء�

		//first->data++;
	}
	last->next = NULL;
	//cout << "first->data��" << first->data << endl;
}

template<class DataType>
LinkList<DataType>::~LinkList() {  // ɾ������Ԫ��
	while (first != NULL)  // ֻҪͷָ���н��ָ�򣬾�ɾ���ý��
	{
		Node<DataType> *del_node = first;
		first = first->next;  //  ͷָ��ÿ�ƶ�����һ�����󣬾�ɾ��ǰ���Ǹ���㡣
		delete del_node;
	}
}

template<class DataType>
int LinkList<DataType>::getLength() {  // ���ֻ�ȡ�ĳ��ȵķ�ʽ�ʺ��������ݲ����ر���������ر��Ľ�����ͷ���洢���ȵķ�ʽ��
	Node<DataType>* cursor = first->next;
	int count = 0;
	while (cursor != NULL) { 
		cursor = cursor->next;
		count++;
		cout << "cout=" << count << ", address=" << cursor << endl;
	}
	return count;
}

template<class DataType>
DataType LinkList<DataType>::getValue(int i) {
	Node<DataType>* cursor = first->next;
	int count = 1;  // ���������һ��Ԫ���±���"0"�������������ֵ��һ�㶼��ΪԪ���Ǵ�1��ʼ�ġ�
	while (cursor != NULL && count < i) {
		cursor = cursor->next;
		count++;
	}
	if (cursor == NULL) throw "Index out of range! index=" + i;
	else return cursor->data;
}

template<class DataType>
int LinkList<DataType>::getIndex(DataType data) {
	Node<DataType>* cursor = first->next;
	int count = 1;  
	while (cursor != NULL && cursor->data != data) {
		cursor = cursor->next;
		count++;
	}
	if (cursor == NULL) throw "Can't find value is: " + data;
	else return count;
}

template<class DataType>
void LinkList<DataType>::insertData(int i, DataType data) {
	Node<DataType>* cursor = first->next;
	int count = 1;
	while (cursor != NULL && count < i-1) {
		cursor = cursor->next;
		count++;
	}
	if (cursor == NULL) throw "Index out of range! index=" + i;
	else {
		Node<DataType>* node = new Node<DataType>;  // ������Ľ��
		node->data = data;
		node->next = cursor->next;
		cursor->next = node;

		//first->data++;
	}
}

template<class DataType>
DataType LinkList<DataType>::deleteData(int i) {
	Node<DataType>* cursor = first;
	int count = 0;  // �ӡ�0����ʼ����Ϊ�˼��listֻ��һ��Ԫ�ص����
	while (cursor != NULL && count < i - 1) {  // ȡ��ɾ��Ԫ�ص�ǰһ��Ԫ��
		cursor = cursor->next;
		count++;
	}
	if (cursor == NULL || cursor->next == NULL) throw "Index out of range! index=" + i;
	else {
		DataType node_data;
		Node<DataType>* node = new Node<DataType>;  // ��ɾ���Ľ��
		node = cursor->next;
		node_data = node->data;  // ��ű�ɾ������ֵ
		cursor->next = node->next;
		delete node;

		//first->data--;
		return node_data;
	}
}

template<class DataType>
void LinkList<DataType>::printList() { 
	Node<DataType> * cursor = first->next;
	while (cursor != NULL) {  // ��ӡʱ��ͷָ�벻���ƶ������Բ�������������������ͷָ����ѭ��������
		cout << "==> " << cursor->data << ", addr= " << cursor << endl;
		cursor = cursor->next;
	}
}

int main() {
	int arr[] = { 11,22,33,44,55 };
	LinkList<int> list(arr, 5);
	//list.printList();
	//cout << "list's length is: " << list.getLength() << endl;
	//cout << "list's value is: " << list.getValue(4) << endl;
	//cout << "list's index is: " << list.getIndex(33) << endl;
	//list.insertData(3, 99);
	//list.printList();
	//cout << "list's delete is: " << list.deleteData(5) << endl;
	list.printList();
}