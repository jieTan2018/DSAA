#pragma once
// ����������
#include<iostream>

template<class DataType>
struct BiNode {
	int data;
	BiNode<DataType>* lchild, * rchild;
};

class BiSortTree {  // ͨ���������int�͵ģ������������͵����ݣ�����Ҳ��ת��Ϊ��Ӧ��intֵ��
private:
	BiNode<int>* root;
	BiNode<int>* parent;
	void release(BiNode<int>* node);
	BiNode<int>* remveNode(BiNode<int>* node, BiNode<int>* parent);
	BiNode<int>* findNode(BiNode<int>* root, int data, BiNode<int>** parent_ptr=NULL);
public:
	BiSortTree(int * init_array, int arr_length);
	~BiSortTree() { release(root); }
	void insert(BiNode<int>** root_ptr, BiNode<int>* node);  //ָ��ָ���ָ�룺root_ptr��ָ��rootָ���ָ��
	void remove(int data);
	BiNode<int>* search(int data) { return findNode(root, data); }
};

BiSortTree::BiSortTree(int* init_array, int arr_length) {
	root = NULL;  // ����ֵ��Ĭ��Ҳ����ΪNULL�������������ᾯ�档
	parent = NULL;
	for (int i = 0; i < arr_length; i++) {
		BiNode<int>* node=new BiNode<int>();  // "()"����Ĭ�ϳ�ʼ��ֵ��data=0�� lchild=NULL, rchild=NULL
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
	// 1��node��Ҷ�ӽ��
	if (node->lchild == NULL && node->rchild == NULL) {
		if (parent->lchild == node) parent->lchild = NULL;
		else parent->rchild = NULL;
		return node;
	}
	// 2��node�����������е���� | �ص㣡����
	if (node->lchild != NULL && node->rchild != NULL) {
		BiNode<int>* tmp_parent = node;  // ����һ����ʱ���ڵ�
		BiNode<int>* cursor = node->rchild;
		while (cursor->lchild != NULL)
		{ // Ѱ�������㣨��������ֵ��С�Ľ�㣩
			tmp_parent = cursor;
			cursor = cursor->lchild;
		}
		node->data = cursor->data;
		if (tmp_parent == node)node->rchild = cursor->rchild;
		else tmp_parent->lchild = cursor->rchild;
		return cursor;
	}
	// 3��nodeֻ�����������������Ľ��
	if (node->rchild == NULL) {  // ֻ��������
		if (parent->lchild == node) parent->lchild = node->lchild;
		else parent->rchild = node->lchild;
		return node;
	}
	else
	{  // ֻ��������
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
