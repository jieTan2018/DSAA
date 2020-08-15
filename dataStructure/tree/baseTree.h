/*
** �������ĳ�����
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
	BiNode<DataType>* root;  //ָ�������ͷָ�� | ע��û��������ͷ��������������ҪŪ���ˣ�
	BiNode<DataType>* create(BiNode<DataType>* bt, char position = '-');  // ����������
	void release(BiNode<DataType>* bt); // �ͷŶ��������ͷ��Դ���Ľ��Ϊ�����Ķ�����
	virtual void preOrder(BiNode<DataType>* bt) = 0;  // �������
	virtual void inOrder(BiNode<DataType>* bt) = 0;  // �������
	virtual void postOrder(BiNode<DataType>* bt) = 0;  // �������
public:
	BaseTree() { root = create(root); }
	~BaseTree() { release(root); }
	void PreOrder() { preOrder(root); }
	void InOrder() { inOrder(root); }
	void PostOrder() { postOrder(root); }
	void LevelOrder();  // Ҫ�õ�����
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
	LinkQueue<BiNode<DataType>*> Q;  // ��ģ�����ʼ������
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
