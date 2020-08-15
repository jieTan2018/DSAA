#pragma once
#include"baseTree.h"
using namespace std;
template<class DataType>
class BiTree: virtual public BaseTree<DataType> {
protected:
	void preOrder(BiNode<DataType>* bt);  // 先序遍历
	void inOrder(BiNode<DataType>* bt);  // 中序遍历
	void postOrder(BiNode<DataType>* bt);  // 后序遍历
};

template<class DataType>
void BiTree<DataType>::preOrder(BiNode<DataType>* bt) {
	if (bt == NULL)return;
	else
	{
		cout << bt->data << " ";
		preOrder(bt->lchild);
		preOrder(bt->rchild);
	}
}

template<class DataType>
void BiTree<DataType>::inOrder(BiNode<DataType>* bt) {
	if (bt == NULL)return;
	else
	{
		inOrder(bt->lchild);
		cout << bt->data << " ";
		inOrder(bt->rchild);
	}
}

template<class DataType>
void BiTree<DataType>::postOrder(BiNode<DataType>* bt) {
	if (bt == NULL)return;
	else
	{
		postOrder(bt->lchild);
		postOrder(bt->rchild);
		cout << bt->data << " ";
	}
}