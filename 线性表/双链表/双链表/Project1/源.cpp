#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//˫����Ĳ��룬��ʼ����ɾ��,��λ���ң��󳤶ȣ�β�巨���������
typedef struct dnode* dlinklist; // ��ǰ���� dlinklist ��ָ�� dnode ��ָ��
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
	printf("���������֣�����99999ʱֹͣ��\n");
	scanf_s("%d", &x); //����������д��x�ĵ�ַ
	dlinklist a=l,b;


	while (x != 99999) {
		b = (dlinklist)malloc(sizeof(dnode));//Ϊb�����£�����ռ�
		b->next = NULL;
		b->data = x;
		b->prior = a;
		a->next = b;
		a = b;
		scanf_s("%d", &x);//�����µ���ֵx
	}
	printf("��������ɡ�\n");
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
		cout << "����λ�ò�����" << endl;
		return;
	}
	dlinklist a = l;
	int i = 0;
	while (a->next != NULL&&i!=n) {
		i++;
		a = a->next;
	}
	if (a != NULL)
		cout << "��" << n << "λ��ֵΪ" << a->data << endl;
	else
		cout << "����ʧ�ܣ��ڵ㲻���ڡ�" << endl;
}

void charu(dlinklist& l,int n,int m) {
	int ii = chang(l);
	if (n <= 0 || n > ii + 1) {
		cout << "��ѡλ�ò�����" << endl;
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
		cout << "��ѡλ�ò�����" << endl;
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
	if (temp ->next!= NULL) {//β�ڵ�nextΪ��
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