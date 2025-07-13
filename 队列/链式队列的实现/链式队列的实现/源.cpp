//链式队列的初始化，判空，入队，出队，循环入队构建,打印

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct linknode {
	int data;
	struct linknode* next;
}linknode,*node;//节点，包括数据域和指向下一个节点的指针域

typedef struct {
	node front, rear;
}linkqueue;//链式队列，包括头和位的指针

void initqueue(linkqueue& a) {
	a.front = a.rear = (node)malloc(sizeof(linknode));//开辟一个节点的空间，初始化时，队列为空，首尾指针指向相同空间
	a.front->next = NULL;//头节点指向的下一个节点此时无内容
	return;
}

bool isempty(linkqueue& a) {
	return(a.front == a.rear);//头尾相等，为空，返回ture
}

void outqueue(linkqueue& a) {
	if (isempty(a)) {
		cout << "队列为空，无法出队" << endl;
		return;
	}
	
	else {
		cout << "出队元素为" << a.front->next->data << endl;
		node n;
		if (a.front->next->next==NULL) {//删除了最后一个节点(首个数据节点后的节点为空)
			n = a.rear;
			a.front->next = NULL;
			a.rear = a.front;
			free(n);
		}
		else {
			n = a.front->next;
			a.front->next = n->next;
			free(n);
		}
	}
	return;
}
void enqueue(linkqueue& a, int x) {
	node n;
	n = (node)malloc(sizeof(linknode));
	n->data = x;
	n->next = NULL;
	a.rear->next = n;
	a.rear = n;
	return;
}

void enenqueue(linkqueue& a) {
	int x;
	cout << "请输入队数字（99999时结束）" << endl;
	cin >> x;
	while (x != 99999) {
		enqueue(a, x);
		cin >> x;
	}
	
	return;
}

void printqueue(const linkqueue& a) {
	node x = a.front;
	while (x->next != NULL) {
		cout << x->next->data<<" ";
		x = x->next;
		if (x == a.rear) {
			break;
		}
	}
	cout << endl;
	return;
}

int main() {
	linkqueue a;
	initqueue(a);
	enenqueue(a);
	printqueue(a);
	enqueue(a, 1023);
	enqueue(a, 2025);
	printqueue(a);
	outqueue(a);
	printqueue(a);

	return 0;
}