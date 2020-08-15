/*
** 基于栈的二叉树非递归遍历的实现 **
** 思路来由：递归操作顺序就是入栈后出栈的顺序。最外层的函数在栈底，递归到正式执行的函数在栈顶。
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
	void preOrder(BiNode<DataType>* bt);  // 先序遍历
	void inOrder(BiNode<DataType>* bt);  // 中序遍历
	void postOrder(BiNode<DataType>* bt);  // 后序遍历
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
