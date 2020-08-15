/*
** 二叉树的抽象类
*/
#pragma once
#include "linkQueue.h"
using namespace std;
template<class DataType>
struct BiNode
{
	DataType data;
	BiNode* lchild, * rchild;
};

template<class DataType>
class BaseTree {
private:
	int level = 1;
protected:
	DataType end_flag = "#";
	BiNode<DataType>* root;  //指向根结点的头指针 | 注意没有链表中头结点这个东西，不要弄混了！
	BiNode<DataType>* create(BiNode<DataType>* bt, char position = '-');  // 创建二叉树
	void release(BiNode<DataType>* bt); // 释放二叉树：释放以传入的结点为根结点的二叉数
	virtual void preOrder(BiNode<DataType>* bt) = 0;  // 先序遍历
	virtual void inOrder(BiNode<DataType>* bt) = 0;  // 中序遍历
	virtual void postOrder(BiNode<DataType>* bt) = 0;  // 后序遍历
public:
	BaseTree() { root = create(root); }
	~BaseTree() { release(root); }
	void PreOrder() { preOrder(root); }
	void InOrder() { inOrder(root); }
	void PostOrder() { postOrder(root); }
	void LevelOrder();  // 要用到队列
};

template<class DataType>
BiNode<DataType>* BaseTree<DataType>::create(BiNode<DataType>* bt, char position) {
	cout << "current level:" << level << ", position:" << position << endl;
	DataType data;
	cin >> data;
	if (data == end_flag) {
		bt = NULL;
	}
	else {
		bt = new BiNode<DataType>;
		bt->data = data;
		level++;
		bt->lchild = create(bt->lchild, 'L');
		bt->rchild = create(bt->rchild, 'R');
	}

	if (position == 'R') level--;
	return bt;
}

template<class DataType>
void BaseTree<DataType>::release(BiNode<DataType>* bt) {
	//cout << "release is run!\n";
	if (bt != NULL) {
		cout << "bt->data: " << bt->data << ", &bt:" << bt << ", bt->lchild: " << bt->lchild << ", bt->rchild: " << bt->rchild << endl;
		release(bt->lchild);
		release(bt->rchild);
		delete bt;
	}
}

template<class DataType>
void BaseTree<DataType>::LevelOrder() {
	LinkQueue<BiNode<DataType>*> Q;  // 用模板结点初始化队列
	if (root == NULL) return;
	Q.enter(root);
	while (!Q.isEmpty())
	{
		BiNode<DataType>* node = Q.shift();
		cout << node->data << " ";
		if (node->lchild != NULL)Q.enter(node->lchild);
		if (node->rchild != NULL)Q.enter(node->rchild);
	}
}
