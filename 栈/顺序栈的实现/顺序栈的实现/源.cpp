//顺序栈的实现，初始化，判空，入栈，出栈，读取栈顶元素
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define max 50
typedef struct {
	int data[max];
	int top;//栈顶指针
}sqstack;

void chushi(sqstack &s) {
	s.top = -1;
	return;
}

bool orempty(sqstack &s) {
	if (s.top == -1) {

		return true;
	}
	else{
		return false;
	}
}

void push(sqstack& s, int x) {
	if (s.top == max-1) {
		cout << "栈已满" << endl;
		return;
	}
	s.top++;
	s.data[s.top] = x;
	return;
}

bool pop(sqstack& s) {
	if (s.top == -1) {
		cout << "栈为空" << endl;
		return false;
	}
	int x;
	x = s.data[s.top];
	s.top--;
	cout << "出栈元素为" << x << endl;
	return true;
}

void gettop(sqstack& s) {
	if (s.top == -1) {
		cout << "栈为空" << endl;
		return;
	}
	cout << "栈顶元素为" << s.data[s.top] << endl;
}

void jianzhan(sqstack& s) {//循环建栈
	int x;
	printf("请输入数字，输入99999时停止：\n");
	cin >> x; 
	while (x != 99999) {
		if (s.top >= max-1) {
			cout << "最大长度超出容量" << endl;
			return;
		}
		s.top++;
		s.data[s.top ]=x;
		cin>>x;//输入新的数值x
	}
	return;
}

void dayin(sqstack s) {
	while (s.top != -1) {
		cout << s.data[s.top] << " ";
		s.top--;
	}
	cout << endl;
	return;
}

int main() {
	sqstack a;
	chushi(a);
	jianzhan(a);
	push(a, 20);
	push(a, 30);
	dayin(a);
	bool x=pop(a);
	dayin(a);
	gettop(a);
	
	return 0;
}