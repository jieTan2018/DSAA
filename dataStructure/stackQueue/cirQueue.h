/*
名称：循环队列		=> 基于数组
*/
template<class DataType>
class CirQueue {
private:
	const int QUEUE_SIZE;  // 此处未给初始值，则必需在构造函数中初始化！
	int front, rear;
	DataType *queue;
public:
	CirQueue(int q_size = 100) :QUEUE_SIZE(q_size + 1) { front = rear = 0; queue = new DataType[QUEUE_SIZE]; }  // q_size + 1：多申请一个位置，保证队满、对空容易判定！
	~CirQueue(){}
	void enter(DataType data);  // 入队操作
	DataType shift();  // 出队操作
	DataType getFront();  // 获得队头元素值
	void show();  // 打印队列元素
	bool isEmpty() { return front == rear ? true : false; }  // 队空
	bool isFull() { return (rear + 1) % QUEUE_SIZE == front ? true : false; }  // 队满
	int size() { return rear - front; }  // 返回元素的个数。
};

template<class DataType>
void CirQueue<DataType>::enter(DataType data) {
	if (isFull()) throw "Queue full !";
	rear %= QUEUE_SIZE;
	queue[rear++] = data;  // int++: 是先用了再加一，所以不会存在越界的情况！
}

template<class DataType>
DataType CirQueue<DataType>::shift() {
	if (isEmpty()) throw "Queue empty !";
	return queue[(front++) % QUEUE_SIZE];  // 取出对头元素时，front位置是后移的。
}

template<class DataType>
DataType CirQueue<DataType>::getFront() {
	if (isEmpty()) throw "Queue empty !";
	return queue[front % QUEUE_SIZE];  //获取对头元素值时，front位置不变！
}

template<class DataType>
void CirQueue<DataType>::show() {
	int cursor = front % QUEUE_SIZE;
	while (cursor != rear)
	{
		cursor %= QUEUE_SIZE;
		std::cout << queue[cursor++] << " ";
	}
}