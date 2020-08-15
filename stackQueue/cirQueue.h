/*
���ƣ�ѭ������		=> ��������
*/
template<class DataType>
class CirQueue {
private:
	const int QUEUE_SIZE;  // �˴�δ����ʼֵ��������ڹ��캯���г�ʼ����
	int front, rear;
	DataType *queue;
public:
	CirQueue(int q_size = 100) :QUEUE_SIZE(q_size + 1) { front = rear = 0; queue = new DataType[QUEUE_SIZE]; }  // q_size + 1��������һ��λ�ã���֤�������Կ������ж���
	~CirQueue(){}
	void enter(DataType data);  // ��Ӳ���
	DataType shift();  // ���Ӳ���
	DataType getFront();  // ��ö�ͷԪ��ֵ
	void show();  // ��ӡ����Ԫ��
	bool isEmpty() { return front == rear ? true : false; }  // �ӿ�
	bool isFull() { return (rear + 1) % QUEUE_SIZE == front ? true : false; }  // ����
	int size() { return rear - front; }  // ����Ԫ�صĸ�����
};

template<class DataType>
void CirQueue<DataType>::enter(DataType data) {
	if (isFull()) throw "Queue full !";
	rear %= QUEUE_SIZE;
	queue[rear++] = data;  // int++: ���������ټ�һ�����Բ������Խ��������
}

template<class DataType>
DataType CirQueue<DataType>::shift() {
	if (isEmpty()) throw "Queue empty !";
	return queue[(front++) % QUEUE_SIZE];  // ȡ����ͷԪ��ʱ��frontλ���Ǻ��Ƶġ�
}

template<class DataType>
DataType CirQueue<DataType>::getFront() {
	if (isEmpty()) throw "Queue empty !";
	return queue[front % QUEUE_SIZE];  //��ȡ��ͷԪ��ֵʱ��frontλ�ò��䣡
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