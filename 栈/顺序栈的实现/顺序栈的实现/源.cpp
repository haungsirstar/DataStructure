//˳��ջ��ʵ�֣���ʼ�����пգ���ջ����ջ����ȡջ��Ԫ��
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define max 50
typedef struct {
	int data[max];
	int top;//ջ��ָ��
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
		cout << "ջ����" << endl;
		return;
	}
	s.top++;
	s.data[s.top] = x;
	return;
}

bool pop(sqstack& s) {
	if (s.top == -1) {
		cout << "ջΪ��" << endl;
		return false;
	}
	int x;
	x = s.data[s.top];
	s.top--;
	cout << "��ջԪ��Ϊ" << x << endl;
	return true;
}

void gettop(sqstack& s) {
	if (s.top == -1) {
		cout << "ջΪ��" << endl;
		return;
	}
	cout << "ջ��Ԫ��Ϊ" << s.data[s.top] << endl;
}

void jianzhan(sqstack& s) {//ѭ����ջ
	int x;
	printf("���������֣�����99999ʱֹͣ��\n");
	cin >> x; 
	while (x != 99999) {
		if (s.top >= max-1) {
			cout << "��󳤶ȳ�������" << endl;
			return;
		}
		s.top++;
		s.data[s.top ]=x;
		cin>>x;//�����µ���ֵx
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