//循环顺序队列的初始化，判空，入队，出队，循环入队构建队列
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

bool isnotempty(const queue& a) {//常量引用，不改变参数
	return a.front == a.rear;//不等返回false,相等为空队列，返回ture
}

void enqueue(queue& a, int b) {
	if ((a.rear+1)%max==a.front) {
		cout << "队列已满，无法入队" << endl;
		return;
	}
	else {
		a.data[a.rear] = b;//在当前 rear 位置存入数据
		a.rear = (a.rear + 1) % max;//后移一位
	}

}

int outqueue(queue& a) {
	
	if (isnotempty(a) ){
		cout << "队列为空，无法出队" << endl;
		return -999;
	}
	else {
		int b = a.data[a.front];
		a.front=(a.front+1)%max;//循环
		cout << "出队元素为" << b << endl;
		return b;

	}

}

void enenqueue(queue& a) {
	int x;
	printf("请输入数字，输入99999时停止：\n");
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