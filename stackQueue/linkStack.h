// ��ջ
template<class DataType>
struct StackNode
{
	DataType data;
	StackNode<DataType>* prior;  // �ײ����
};

template<class DataType>
class LinkStack {
private:
	StackNode<DataType>* top;  //ջ��
public:
	LinkStack() { top = NULL; }
	~LinkStack();
	void push(DataType data);
	DataType pop();
	DataType getTop() { if (top != NULL)return top->data; }
	bool isEmpty() { return top == NULL ? true : false; }
	void delNode();
};

template<class DataType>
inline void LinkStack<DataType>::delNode() {  // ��֪��Ϊʲô��top�����������øú������topû���յ��޸ĺ��top��ַ��������
	std::cout << "top:" << top << ", data:" << top->data << std::endl;
	StackNode<DataType>* del_node = top;
	top = top->prior;
	delete del_node;
}

template<class DataType>
LinkStack<DataType>::~LinkStack() {
	while (top != NULL)
	{
		delNode();
	}
}

template<class DataType>
void LinkStack<DataType>::push(DataType data) {
	StackNode<DataType>* node = new StackNode<DataType>;
	node->data = data;
	node->prior = top;
	top = node;
}

template<class DataType>
DataType LinkStack<DataType>::pop() {
	if (top == NULL) throw"stack empty !";
	DataType top_value = top->data;
	delNode();

	return top_value;
}