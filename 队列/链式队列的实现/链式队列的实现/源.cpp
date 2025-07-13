//��ʽ���еĳ�ʼ�����пգ���ӣ����ӣ�ѭ����ӹ���,��ӡ

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct linknode {
	int data;
	struct linknode* next;
}linknode,*node;//�ڵ㣬�����������ָ����һ���ڵ��ָ����

typedef struct {
	node front, rear;
}linkqueue;//��ʽ���У�����ͷ��λ��ָ��

void initqueue(linkqueue& a) {
	a.front = a.rear = (node)malloc(sizeof(linknode));//����һ���ڵ�Ŀռ䣬��ʼ��ʱ������Ϊ�գ���βָ��ָ����ͬ�ռ�
	a.front->next = NULL;//ͷ�ڵ�ָ�����һ���ڵ��ʱ������
	return;
}

bool isempty(linkqueue& a) {
	return(a.front == a.rear);//ͷβ��ȣ�Ϊ�գ�����ture
}

void outqueue(linkqueue& a) {
	if (isempty(a)) {
		cout << "����Ϊ�գ��޷�����" << endl;
		return;
	}
	
	else {
		cout << "����Ԫ��Ϊ" << a.front->next->data << endl;
		node n;
		if (a.front->next->next==NULL) {//ɾ�������һ���ڵ�(�׸����ݽڵ��Ľڵ�Ϊ��)
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
	cout << "����������֣�99999ʱ������" << endl;
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