#include<iostream>
using namespace std;

/*此部分可写在.h文件中*/
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
	//  以前还有从头部插入的写法，才保留了insertEnd。现在删除了头插法，此时insertEnd只是为了展示默认带参数的构造函数的写法而已！
	LinkList(DataType arr[], int length, bool insertEnd=true);  // 此处给了默认值的项，后面实现时参数就不能在给默认值了。
	~LinkList();
	int getLength();  // 获取链表长度
	DataType getValue(int i);  //根据index返回值
	int getIndex(DataType data);  //根据值返回位置
	void insertData(int i, DataType data);  // 在第i个位置上，插入数据
	DataType deleteData(int i);  //删除第i个位置上的数据
	void printList();  //打印链表
};

template<class DataType>
LinkList<DataType>::LinkList() {  // 默认创建一个空链表
	first = new Node<DataType>;
	first->data = 0;  // 用头节点来存放链表的长度
	first->next = NULL;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType arr[], int length, bool insertEnd) {  //用数组初始化一个链表 | 此处 insertEnd不能再给默认值了！
	// 头指针指向第一个元素
	first = new Node<DataType>;
	//first->data = 0;  // 用头节点来存放链表的长度
	first->next = NULL;
	// 后续元素的赋值 || 从元素尾部插入
	Node<DataType>* last = first;  // 定义一个尾指针，指向最后一个元素。| 刚开始，尾指针和头指针位置重合！
	for (int i = 0; i < length; i++) {  // 在每个结点的尾部插入元素。元素增长方向：=>
		Node<DataType>* node = new Node<DataType>;  // 待插入的结点
		node->data = arr[i];
		last->next = node;  // 将前一个元素的next指向要插入的元素。
		last = node;  // 尾指针知道插入的元素。

		//first->data++;
	}
	last->next = NULL;
	//cout << "first->data：" << first->data << endl;
}

template<class DataType>
LinkList<DataType>::~LinkList() {  // 删除链表元素
	while (first != NULL)  // 只要头指针有结点指向，就删除该结点
	{
		Node<DataType> *del_node = first;
		first = first->next;  //  头指针每移动到后一个结点后，就删除前面那个结点。
		delete del_node;
	}
}

template<class DataType>
int LinkList<DataType>::getLength() {  // 这种获取的长度的方式适合链表数据不是特别多的情况。特别多的建议用头结点存储长度的方式。
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
	int count = 1;  // 区别数组第一个元素下标是"0"，而我们输入的值，一般都认为元素是从1开始的。
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
		Node<DataType>* node = new Node<DataType>;  // 待插入的结点
		node->data = data;
		node->next = cursor->next;
		cursor->next = node;

		//first->data++;
	}
}

template<class DataType>
DataType LinkList<DataType>::deleteData(int i) {
	Node<DataType>* cursor = first;
	int count = 0;  // 从“0”开始，是为了兼顾list只有一个元素的情况
	while (cursor != NULL && count < i - 1) {  // 取被删除元素的前一个元素
		cursor = cursor->next;
		count++;
	}
	if (cursor == NULL || cursor->next == NULL) throw "Index out of range! index=" + i;
	else {
		DataType node_data;
		Node<DataType>* node = new Node<DataType>;  // 待删除的结点
		node = cursor->next;
		node_data = node->data;  // 存放被删除结点的值
		cursor->next = node->next;
		delete node;

		//first->data--;
		return node_data;
	}
}

template<class DataType>
void LinkList<DataType>::printList() { 
	Node<DataType> * cursor = first->next;
	while (cursor != NULL) {  // 打印时，头指针不会移动，所以不会像析构里面那样用头指针做循环条件！
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