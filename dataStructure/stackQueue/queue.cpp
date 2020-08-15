#include<iostream>
#include "cirQueue.h"
#include "linkQueue.h"
using namespace std;

int main() {
	/*队列操作*/
	cout << "循环队列：\n";
	CirQueue<int> cir_queue(7);
	for (int da : { 1, 2, 3, 4, 5, 6, 7 }) cir_queue.enter(da);
	cout << "cir_queue:\n";
	cir_queue.show();
	cout << endl;
	cout << "cir_queue size：" << cir_queue.size() << endl;
	cout << "front param：" << cir_queue.shift()<< endl;
	cout << "front param：" << cir_queue.getFront() << endl;
	cout << "cir_queue size：" << cir_queue.size() << endl;

	cout << "链队列：\n";
	LinkQueue<int> link_queue;
	for (int da = 1; da < 100; da++) link_queue.enter(da*da);
	cout << "link_queue:\n";
	link_queue.show();
	cout << endl;
	cout << "link_queue size：" << link_queue.size() << endl;
	for (int i = 1; i < 10; i++) cout << "i=" << i << ", front param：" << link_queue.shift() << endl;
	cout << "front param：" << link_queue.getFront() << endl; 
	cout << "link_queue size：" << link_queue.size() << endl;

}