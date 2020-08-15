#pragma once
// 二叉排序树
#include<iostream>

template<class DataType>
struct BiNode {
	int data;
	BiNode<DataType>* lchild, * rchild;
};

class BiSortTree {  // 通常都是针对int型的，若有其他类型的数据，最终也是转换为相应的int值。
private:
	BiNode<int>* root;
	BiNode<int>* parent;
	void release(BiNode<int>* node);
	BiNode<int>* remveNode(BiNode<int>* node, BiNode<int>* parent);
	BiNode<int>* findNode(BiNode<int>* root, int data, BiNode<int>** parent_ptr=NULL);
public:
	BiSortTree(int * init_array, int arr_length);
	~BiSortTree() { release(root); }
	void insert(BiNode<int>** root_ptr, BiNode<int>* node);  //指向指针的指针：root_ptr是指向root指针的指针
	void remove(int data);
	BiNode<int>* search(int data) { return findNode(root, data); }
};

BiSortTree::BiSortTree(int* init_array, int arr_length) {
	root = NULL;  // 不赋值，默认也会置为NULL，不过编译器会警告。
	parent = NULL;
	for (int i = 0; i < arr_length; i++) {
		BiNode<int>* node=new BiNode<int>();  // "()"给定默认初始化值：data=0， lchild=NULL, rchild=NULL
		node->data = init_array[i];
		insert(&root, node);
	}
}

void BiSortTree::release(BiNode<int>* node) {
	if (node == NULL)return;
	release(node->lchild);
	release(node->rchild);
	std::cout << "delete node:" << node << ", data:" << node->data << ", lchild:" << node->lchild << ", rchild:" << node->rchild << std::endl;
	delete node;
}

void BiSortTree::insert(BiNode<int>**root_ptr, BiNode<int>* node) {
	if (*root_ptr == NULL) *root_ptr = node;
	else
	{
		if (node->data < (*root_ptr)->data)insert(&((*root_ptr)->lchild), node);
		else insert(&((*root_ptr)->rchild), node);
	}
}

BiNode<int>* BiSortTree::remveNode(BiNode<int>* node, BiNode<int>* parent) {
	if (node == NULL) return NULL;
	// 1、node是叶子结点
	if (node->lchild == NULL && node->rchild == NULL) {
		if (parent->lchild == node) parent->lchild = NULL;
		else parent->rchild = NULL;
		return node;
	}
	// 2、node左、右子树都有的情况 | 重点！！！
	if (node->lchild != NULL && node->rchild != NULL) {
		BiNode<int>* tmp_parent = node;  // 申请一个临时父节点
		BiNode<int>* cursor = node->rchild;
		while (cursor->lchild != NULL)
		{ // 寻找最左结点（右子树中值最小的结点）
			tmp_parent = cursor;
			cursor = cursor->lchild;
		}
		node->data = cursor->data;
		if (tmp_parent == node)node->rchild = cursor->rchild;
		else tmp_parent->lchild = cursor->rchild;
		return cursor;
	}
	// 3、node只有左子树或右子树的结点
	if (node->rchild == NULL) {  // 只有左子树
		if (parent->lchild == node) parent->lchild = node->lchild;
		else parent->rchild = node->lchild;
		return node;
	}
	else
	{  // 只有右子树
		if (parent->lchild == node) parent->lchild = node->rchild;
		else parent->rchild = node->rchild;
		return node;
	}
}

void BiSortTree::remove(int data) {
	BiNode<int>* node = findNode(root, data, &parent);
	if (node == NULL) { std::cout <<__FUNCTION__<<":Could not find the node which data is: " << data << std::endl; return; }
	if (parent == NULL)delete root;
	else
	{
		delete remveNode(node, parent);
	}
}

BiNode<int>* BiSortTree::findNode(BiNode<int>* node, int data, BiNode<int>** parent_ptr) {
	if (node == NULL)return NULL;
	if (parent_ptr) {
		while (node!=NULL && node->data != data)
		{
			*parent_ptr = node;
			if (data < node->data)node = node->lchild;
			else node = node->rchild;
		}
	}
	else
	{
		while (node != NULL && node->data != data)
		{
			if (data < node->data)node = node->lchild;
			else node = node->rchild;
		}
	}
	
	return node;
}
