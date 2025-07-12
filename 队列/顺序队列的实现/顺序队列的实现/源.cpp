//ѭ��˳����еĳ�ʼ�����пգ���ӣ����ӣ�ѭ����ӹ�������
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define max 50
typedef struct {
	int data[max];
	int front, rear;
}queue;

void initqueue(queue &a) {
	a.front = a.rear = 0;
}

bool isnotempty(const queue& a) {//�������ã����ı����
	return a.front == a.rear;//���ȷ���false,���Ϊ�ն��У�����ture
}

void enqueue(queue& a, int b) {
	if ((a.rear+1)%max==a.front) {
		cout << "�����������޷����" << endl;
		return;
	}
	else {
		a.data[a.rear] = b;//�ڵ�ǰ rear λ�ô�������
		a.rear = (a.rear + 1) % max;//����һλ
	}

}

int outqueue(queue& a) {
	
	if (isnotempty(a) ){
		cout << "����Ϊ�գ��޷�����" << endl;
		return -999;
	}
	else {
		int b = a.data[a.front];
		a.front=(a.front+1)%max;//ѭ��
		cout << "����Ԫ��Ϊ" << b << endl;
		return b;

	}

}

void enenqueue(queue& a) {
	int x;
	printf("���������֣�����99999ʱֹͣ��\n");
	cin >> x;
	
	while (x != 99999 && (a.rear + 1) % max != a.front) {
		a.data[a.rear] = x;
		a.rear=(a.rear+1)%max;
		cin >> x;
	}
	return;

}

void printqueue(queue a) {
	while (a.front != a.rear) {
		cout << a.data[a.front] << " ";
		a.front = (a.front + 1) % max;
	}
	cout << endl;
	return;
}

int main() {
	queue a;
	initqueue(a);
	enenqueue(a);
	printqueue(a);
	enqueue(a, 99);
	enqueue(a, 102);
	printqueue(a);
	outqueue(a);
	printqueue(a);

}