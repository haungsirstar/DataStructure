//����˳���ĳ�ʼ��������ɾ������ֵ���ң���λ����

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MaxSize 50
typedef struct {
	int data[MaxSize];
	int chang;
} shunxu;//�����˽ṹ��shunxu

void printlist(shunxu& L) {
	for (int i = 0; i < L.chang; i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
}

void shuru(shunxu& L,int list[], int n) {
	
	if (n > MaxSize) {
		cout << "��󳤶ȳ�������" << endl;
		n = MaxSize;//������Ϊ50������Ĳ�Ҫ��
	}
	for (int i = 0; i < MaxSize&&i<n; i++) {
		L.data[i] = list[i];//���鲻��ֱ����ȣ���Ҫ���θ�ֵ
	}
	L.chang = n;
}

void chushi(shunxu& L) {
	L.chang = 0;//�趨Ŀǰ����Ϊ0
}

void charu(shunxu& L,int a,int b) {
	if (a > MaxSize||a<1||a>L.chang+1) {
		cout << "����λ����Ч" << endl;
		return;
	}
	if (L.chang == MaxSize) {
		cout << "�����޷�����" << endl;
		return;
	}
	for (int i = L.chang;i>=a;i--) {
		L.data[i] = L.data[i - 1];//�����һ��ֵ��ʼ��ֵ��ֵΪǰһ��ֵ
		
	}
	L.data[a - 1] = b;//����λ�õ��ڲ���ֵ
	L.chang++;
}
void chazhi(shunxu&L, int a) {
	for (int i = 0; i < L.chang; i++) {
		if (L.data[i] == a) {
			cout << "ֵΪ " << a << " �������ڵ� " << i + 1 << " λ" << endl;
			return;
		}
	}
	cout << "�������ݲ�����" << endl;
}

void chawei(shunxu& L, int a) {
	if (a<1 || a>L.chang) {
		cout << "���ҵ�λ�ò�����" << endl;
		return;
	}
	cout << "��" << a << "λ����ֵΪ" << L.data[a - 1] << endl;

}
void shanchu(shunxu& L,int a) {
	if (a<1 || a>L.chang) {
		cout << "��λ�ò�����" << endl;
		return;
	}
	for (int i = a - 1; i < L.chang-1; i++) {
		L.data[i] = L.data[i + 1];
	}
	L.chang--;
}
int main() {
	shunxu a;//��������Ϊa��shunxu�ṹ��
	chushi(a); //��ʼ��a
	int list[] = {1, 2, 3, 5, 6, 7, 2, 1, 3};
	shuru(a, list, 9);
	printlist(a);
	int c = 3, d = 100;
	charu(a, c, d);//�ڵ�c��λ�ò���ֵΪd������
	printlist(a);
	chawei(a, 5);
	shanchu(a, 4);// ɾ�����ĸ�λ��
	printlist(a);
}