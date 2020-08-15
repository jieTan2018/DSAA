/*
** ����ջ�Ķ������ǵݹ������ʵ�� **
** ˼·���ɣ��ݹ����˳�������ջ���ջ��˳�������ĺ�����ջ�ף��ݹ鵽��ʽִ�еĺ�����ջ����
*/
#pragma once
#include "linkStack.h"
using namespace std;
template<class DataType>
struct BiFlagNode {
	BiNode<DataType>* bi_node;
	int flag;
	BiFlagNode(BiNode<DataType>* bi_node, int flag):bi_node(bi_node), flag(flag){}
};

template<class DataType>
class BiStackTree: virtual public BaseTree<DataType> {
private:
	LinkStack<BiNode<DataType>*> stack;
protected:
	void preOrder(BiNode<DataType>* bt);  // �������
	void inOrder(BiNode<DataType>* bt);  // �������
	void postOrder(BiNode<DataType>* bt);  // �������
};

template<class DataType>
void BiStackTree<DataType>::preOrder(BiNode<DataType>* bt) {
	if (bt == NULL)return;

	while (bt != NULL || !stack.isEmpty())
	{
		while (bt != NULL)
		{
			cout << bt->data << " ";
			stack.push(bt);
			bt = bt->lchild;
		}
		bt = stack.pop();
		bt = bt->rchild;
	}
}

template<class DataType>
void BiStackTree<DataType>::inOrder(BiNode<DataType>* bt) {
	if (bt == NULL)return;
	
	while (bt != NULL || !stack.isEmpty())
	{
		while (bt != NULL)
		{
			stack.push(bt);
			bt = bt->lchild;
		}
		bt = stack.pop();
		cout << bt->data << " ";
		bt = bt->rchild;
	}
}

template<class DataType>
void BiStackTree<DataType>::postOrder(BiNode<DataType>* bt) {
	if (bt == NULL)return;
	
	LinkStack<BiFlagNode<DataType>*> stack;
	BiFlagNode<DataType>* bf_node;
	while (bt != NULL || !stack.isEmpty())
	{
		while (bt != NULL)
		{
			bf_node = new BiFlagNode<DataType>(bt, 1);
			stack.push(bf_node);
			bt = bt->lchild;
		}
		while (!stack.isEmpty() && stack.getTop()->flag == 2)
		{
			bt = stack.pop()->bi_node;
			cout << bt->data << " ";
		}
		if (!stack.isEmpty()) {
			bf_node = stack.getTop();
			bf_node->flag = 2;
			bt = bf_node->bi_node->rchild;
		}
		else bt = NULL;
	}
}
