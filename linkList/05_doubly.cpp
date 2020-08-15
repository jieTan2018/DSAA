#include<iostream>
using namespace std;

/*此部分可写在.h文件中*/
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
	int getLength();  // 获取链表长度
	int getIndex(DataType data);  //根据值返回位置
	void insertData(int i, DataType data, bool is_add=false);  // 在第i个位置上，插入数据
	DataType deleteData(int i);  //删除第i个位置上的数据
	void printList();  //打印链表

	Node<DataType>* getNode(int i);  //根据index返回结点
	inline Node<DataType>* addNode(Node<DataType>* prior_node, DataType data);  //增加结点
};

template<class DataType>
LinkList<DataType>::LinkList() {  // 默认创建一个空链表
	first = new Node<DataType>;
	first->data = 0;  // 用头节点来存放链表的长度
	first->prior = first;
	first->next = first;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType arr[], int length) {  //用数组初始化一个链表
	// 头指针指向第一个元素
	first = new Node<DataType>;
	first->data = 0;  // 用头节点来存放链表的长度
	first->prior = first;
	first->next = first;
	// 后续元素的赋值 || 从元素尾部插入
	Node<DataType>* last = first;  // 定义一个尾指针，指向最后一个元素。| 刚开始，尾指针和头指针位置重合！
	for (int i = 0; i < length; i++) {  // 在每个结点的尾部插入元素。元素增长方向：=>
		last = addNode(last, arr[i]);  // 尾指针指向插入的元素。
	}
}

template<class DataType>
LinkList<DataType>::~LinkList() {  // 删除链表元素
	Node<DataType>* cursor = first;
	do
	{
		Node<DataType>* del_node = cursor;
		cout << "del_node data: " << del_node->data << ", " << del_node->next << endl;
		cursor = cursor->next;  //  头指针每移动到后一个结点后，就删除前面那个结点。
		delete del_node;
	} while (cursor != first);
}

template<class DataType>
int LinkList<DataType>::getLength() {  // 若不用头结点存储长度的方式，就需要在此处遍历链表（适合数据较小的链表）。
	return first->data;
}

template<class DataType>
Node<DataType>* LinkList<DataType>::getNode(int i) {
	if (i<1 || i>first->data) throw "Index out of range! index=" + i;
	Node<DataType>* cursor = first;
	int count = 0;
	if (i > first->data / 2) { // 从尾部向前查找
		count = first->data + 1;
		do
		{
			//cout << "end count" << count << endl;
			cursor = cursor->prior;
			count--;
		} while (count > i && cursor != first);
	}
	else
	{ // 从头部向后查找
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
	Node<DataType>* node = new Node<DataType>;  // 待插入的结点
	node->data = data;
	node->prior = prior_node;
	node->next = prior_node->next;
	prior_node->next->prior = node;
	prior_node->next = node;
	first->data++;

	return node;
}

template<class DataType>
int LinkList<DataType>::getIndex(DataType data) { // 对比根据index寻找结点，就知道为什么根据值找结点效率要低得多了（根据值，只能从一头遍历走！）
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
	if (is_add) addNode(cursor, data);  // is_add=true： 第 i 个位置上 add 结点（在第 i+1 个结点之后 insert 结点）。
	else addNode(cursor->prior, data);  //  is_add=false：在第 i 个位置上 insert 结点（在第 i-1 个结点之后 add 结点）。
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