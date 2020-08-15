#include<iostream>
#include<string>
#include"biTree.h"
#include"biTree_stack.h"
using namespace std;

int main()
{
	/*cout << "递归遍历二叉树：\n";
	BiTree<string> bt;
	cout << "先序遍历 Preorder: \n";
	bt.PreOrder();
	cout << endl;
	cout << "中序遍历 InOrder: \n";
	bt.InOrder();
	cout << endl;
	cout << "后序遍历 Postorder: \n";
	bt.PostOrder();
	cout << endl;
	cout << "层序遍历 LevelOrder: \n";
	bt.LevelOrder();
	cout << "\n**************************\n";*/

	cout << "非递归遍历二叉树：\n";
	BiStackTree<string> bt_stack;
	cout << "先序遍历 Preorder: \n";
	bt_stack.PreOrder();
	cout << endl;
	cout << "中序遍历 InOrder: \n";
	bt_stack.InOrder();
	cout << endl;
	cout << "后序遍历 Postorder: \n";
	bt_stack.PostOrder();
	cout << endl;
	cout << "层序遍历 LevelOrder: \n";
	bt_stack.LevelOrder();
	cout << endl;
}
