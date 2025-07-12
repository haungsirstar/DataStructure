#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//双链表的插入，初始化，删除,按位查找，求长度，尾插法构建，输出
typedef struct dnode* dlinklist; // 提前声明 dlinklist 是指向 dnode 的指针
typedef struct dnode {
	int data;
	dlinklist prior, next;
}dnode;

void chushi(dlinklist &l) {
	l = (dlinklist)malloc(sizeof(dnode));
	l->prior = NULL;
	l->next = NULL;
	return;
}


void tail(dlinklist& l) {
	int x;
	printf("请输入数字，输入99999时停止：\n");
	scanf_s("%d", &x); //将键盘输入写入x的地址
	dlinklist a=l,b;


	while (x != 99999) {
		b = (dlinklist)malloc(sizeof(dnode));//为b（重新）分配空间
		b->next = NULL;
		b->data = x;
		b->prior = a;
		a->next = b;
		a = b;
		scanf_s("%d", &x);//输入新的数值x
	}
	printf("链表创建完成。\n");
	return;

}

void shuchu(dlinklist l) {
	dlinklist a=l->next;
	while (a!= NULL) {
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
	return;
}

int chang(dlinklist l) {
	int i = 0;
	dlinklist a = l;
	while (a->next != NULL) {
		i++;
		a = a->next;
	}
	return i;
}

void chawei(dlinklist l, int n) {
	int ii = chang(l);
	if (n > ii|| n <= 0) {
		cout << "所查位置不存在" << endl;
		return;
	}
	dlinklist a = l;
	int i = 0;
	while (a->next != NULL&&i!=n) {
		i++;
		a = a->next;
	}
	if (a != NULL)
		cout << "第" << n << "位的值为" << a->data << endl;
	else
		cout << "查找失败，节点不存在。" << endl;
}

void charu(dlinklist& l,int n,int m) {
	int ii = chang(l);
	if (n <= 0 || n > ii + 1) {
		cout << "所选位置不存在" << endl;
		return;
	}
	dlinklist a = l;
	int i = 0;
	while (i != n-1) {
		a = a->next;
		i++;
	}
	dlinklist b;
	b = (dlinklist)malloc(sizeof(dnode));
	b->next = a->next;
	b->prior = a;
	b->data = m;
	if (a->next != NULL) {
		a->next->prior = b;
	}
	a->next = b;
}

void shanchu(dlinklist &l,int n) {
	int ii = chang(l);
	if (n <= 0 || n > ii ) {
		cout << "所选位置不存在" << endl;
		return;
	}
	dlinklist a = l;
	int i = 0;
	while (i != n - 1) {
		a = a->next;
		i++;
	}
	dlinklist temp;	
	
	temp = a->next;
	if (temp ->next!= NULL) {//尾节点next为空
		a->next = temp->next;
	}
	temp->next->prior = a;
	free(temp);
	
}

int main() {
	dlinklist l;
	chushi(l);
	tail(l);
	shuchu(l);
	chawei(l, 3);
	charu(l, 5,99);
	shuchu(l);
	shanchu(l, 2);
	shuchu(l);
}