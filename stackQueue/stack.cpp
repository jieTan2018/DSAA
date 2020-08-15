#include <iostream>
#include "linkStack.h"
#include "seqStack.h"
using namespace std;

int main() {
	// Õ»²Ù×÷
    cout << "Ë³ÐòÕ»£º\n";
    SeqStack<int> seq_stack;
    for (int da : { 1, 2, 3, 4, 5, 6 }) seq_stack.push(da);
    while (!seq_stack.isEmpty())
    {
        cout << "top value:" << seq_stack.pop() << endl;
    }

    cout << "Á´Õ»£º\n";
	LinkStack<int> link_stack;
	for (int da : { 11, 22, 33, 44, 55, 66, 77, 88, 99 }) link_stack.push(da);
	cout << "pop data:" << link_stack.pop() << endl;
}