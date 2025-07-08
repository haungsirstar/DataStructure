//2025年7月7日 带有表头单链表的头插法，尾插法，初始化，求表长，查找，插入删除

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct lnode {
	int data;//数据域
	struct lnode* next;//指针域
}lnode,*linklist;//typedef将struct londe称作lnode，linklist作为其类型的指针

//初始化
bool chushi(linklist &l) {
	l = (linklist)malloc(sizeof(lnode));//为传入的指针分配空间
	if (l == NULL) {
		return false;//malloc失败，返回false
	}
	l->next = NULL;//l指向的结构数据的next为空
	return true;
}

void tail(linklist &l) {//尾插法（输入一个数 → 分配一个空间 → 值为新输入 → b->next为新空间 → b 指向新空间）
	int x;
	printf("请输入数字，输入99999时停止：\n");
	scanf_s("%d", &x); //将键盘输入写入x的地址
	linklist a, b=l;

	
	while (x != 99999) {
		a = (linklist)malloc(sizeof(lnode));//为a（重新）分配空间
		a->data = x;
		b->next = a;//b的指针域为a
		b = a;//b指向a
		//此时b->data=x
		scanf_s("%d", &x);//输入新的数值x
	}
	b->next = NULL;//
	return;
}

void head(linklist &l) {//头插法（输入值，分配新空间，值为输入，新空间next为l后继，l的next为新空间）
	int x;
	printf("请输入数字，输入99999时停止：\n");
	scanf_s("%d", &x); //将键盘输入写入x的地址
	linklist a;	
	while (x != 99999) {
		a = (linklist)malloc(sizeof(lnode));//为a（重新）分配空间
		a->data = x;
		a->next = l->next;//新空间next指向头节点后一个节点
		l->next = a;//l->next指向新空间
		scanf_s("%d", &x);//输入新的数值x
	}
	return;
}

void shuchu(linklist& l) {
	linklist a = l;
	while (a->next != NULL) {
		cout << a->next->data<<" ";
		a = a->next;
	}
	cout << endl;
}

int chang(linklist& l) {
	linklist a = l;
	int i = 0;
	while (a->next!=NULL) {
		a = a->next;
		i++;
	}
	return i;
}

void chazhi(linklist& l, int b) {
	linklist a = l->next;
	int i = 1;
	while (a!=NULL&&a->data != b) {
		i++;
		a = a->next;
	}
	if (a!=NULL) {
		cout << "数据" << b << "在表" << "第" << i << "位" << endl;
	}
	else {
		cout << "所查数据不存在" << endl;
	}
	return;
}

void chawei(linklist& l,int a) {
	linklist b = l;
	int i = 0;
	while(i<a&&b->next!=NULL) {	
		i++;
		b = b->next;
	}
	if (i == a) {
		cout << "第" << a << "位数据的值为" << b->data<<endl;
	}
	else {
		cout << "该位置不存在"<< endl;
	}

	return;
}

void charu(linklist& l, int n, int m) {
	linklist b = l;
	int i = 0;
	int ii = chang(l);
	if (m > ii + 1||m<=0) {
		cout << "插入位置不存在" << endl;
		return;
	}
	while (i < m-1 ) {
		b = b->next;
		i++;
	}
	linklist c = (linklist)malloc(sizeof(lnode));
	c->data = n;
	c->next = b->next;
	b->next = c;
	return;
}
void shanchu(linklist& l, int m) {
	linklist b = l;
	int i = 0;
	int ii = chang(l);
	if (m > ii || m <= 0) {
		cout << "删除的位置不存在" << endl;
		return;
	}
	while (i < m - 1) {
		b = b->next;
		i++;
	}
	linklist temp = b->next;
	b->next=b->next->next;
	free(temp);
}
int main() {
	linklist a;//声明指针变量lnode类型指针a（此时a的内容并不合法）
	chushi(a);//初始化a，为a开辟一个地址，将a指向的结构数据（struct londe型）的next设为NULL
	tail(a);
	shuchu(a);
	int i=chang(a);
	cout << "所求表长为" << i << endl;
	chazhi(a, 99);
	chawei(a, 1);
	charu(a, 999,4);//在第四个位置插入 999
	shuchu(a);
	shanchu(a, 2);//删除第二个位置的数据
	shuchu(a);
	return 0;
}