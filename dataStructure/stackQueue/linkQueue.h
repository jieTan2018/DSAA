// 链队列		=>	基于链表
template<class DataType>
struct QueueNode {
	DataType data;
	QueueNode<DataType>* next;
};

template<class DataType>
class LinkQueue {
private:
	QueueNode<DataType>* front, * rear;
public:
	LinkQueue();
	~LinkQueue();
	void enter(DataType data);
	DataType shift();
	DataType getFront();
	void show();
	bool isEmpty() { return front == rear ? true : false; }
	int size();
};

template<class DataType>
LinkQueue<DataType>::LinkQueue() {
	front = rear = new QueueNode<DataType>();
	rear->next = NULL;
}

template<class DataType>
LinkQueue<DataType>::~LinkQueue() {
	while (front != NULL)
	{
		QueueNode<DataType>* del_node = front;
		front = front->next;
		delete del_node;
	}
}

template<class DataType>
void LinkQueue<DataType>::enter(DataType data) {
	QueueNode<DataType>* node = new QueueNode<DataType>;
	node->data = data;
	node->next = NULL;
	rear->next = node;
	rear = node;
}

template<class DataType>
DataType LinkQueue<DataType>::shift() {
	if (isEmpty())throw "queue empty !";
	QueueNode<DataType>* del_node = front->next;
	DataType front_value = del_node->data;
	if (del_node->next != NULL) front->next = del_node->next;
	else
	{  // 删完就又变成了空链队列！此时将rear有指向front
		front->next = NULL;
		rear = front;
	}
	delete del_node;

	return front_value;
}

template<class DataType>
DataType LinkQueue<DataType>::getFront() {
	if (isEmpty())throw "queue empty !";
	return front->next->data;
}

template<class DataType>
void LinkQueue<DataType>::show() {
	if (isEmpty())throw "queue empty !";
	QueueNode<DataType>* cursor = front;
	do
	{
		cursor = cursor->next;
		std::cout << cursor->data << " ";
	} while (cursor != rear);
}

template<class DataType>
int LinkQueue<DataType>::size() {
	int count = 0;
	QueueNode<DataType>* cursor = front;
	do
	{
		cursor = cursor->next;
		count++;
	} while (cursor != rear);

	return count;
}