// À≥–Ú’ª
template<class DataType>
class SeqStack {
private:
	const int STACK_SIZE;
	DataType *stack; 
	int top; //’ª∂•
public:
	SeqStack(int stack_size = 10) :STACK_SIZE(stack_size) { top = -1; stack = new DataType[STACK_SIZE]; }
	~SeqStack(){}
	void push(DataType data);
	DataType pop();
	DataType getTop() { if (top != -1)return stack[top]; }
	bool isEmpty() { return top != -1 ? false : true; }
};

template<class DataType>
void SeqStack<DataType>::push(DataType data) {
	if (top == STACK_SIZE - 1) throw "Stack full !";
	stack[++top] = data;
}

template<class DataType>
DataType SeqStack<DataType>::pop() {
	if (top == -1)throw "Stack empty !";
	return stack[top--];
}
