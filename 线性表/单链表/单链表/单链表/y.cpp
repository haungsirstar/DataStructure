//2025��7��7�� ���б�ͷ�������ͷ�巨��β�巨����ʼ������������ң�����ɾ��

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct lnode {
	int data;//������
	struct lnode* next;//ָ����
}lnode,*linklist;//typedef��struct londe����lnode��linklist��Ϊ�����͵�ָ��

//��ʼ��
bool chushi(linklist &l) {
	l = (linklist)malloc(sizeof(lnode));//Ϊ�����ָ�����ռ�
	if (l == NULL) {
		return false;//mallocʧ�ܣ�����false
	}
	l->next = NULL;//lָ��Ľṹ���ݵ�nextΪ��
	return true;
}

void tail(linklist &l) {//β�巨������һ���� �� ����һ���ռ� �� ֵΪ������ �� b->nextΪ�¿ռ� �� b ָ���¿ռ䣩
	int x;
	printf("���������֣�����99999ʱֹͣ��\n");
	scanf_s("%d", &x); //����������д��x�ĵ�ַ
	linklist a, b=l;

	
	while (x != 99999) {
		a = (linklist)malloc(sizeof(lnode));//Ϊa�����£�����ռ�
		a->data = x;
		b->next = a;//b��ָ����Ϊa
		b = a;//bָ��a
		//��ʱb->data=x
		scanf_s("%d", &x);//�����µ���ֵx
	}
	b->next = NULL;//
	return;
}

void head(linklist &l) {//ͷ�巨������ֵ�������¿ռ䣬ֵΪ���룬�¿ռ�nextΪl��̣�l��nextΪ�¿ռ䣩
	int x;
	printf("���������֣�����99999ʱֹͣ��\n");
	scanf_s("%d", &x); //����������д��x�ĵ�ַ
	linklist a;	
	while (x != 99999) {
		a = (linklist)malloc(sizeof(lnode));//Ϊa�����£�����ռ�
		a->data = x;
		a->next = l->next;//�¿ռ�nextָ��ͷ�ڵ��һ���ڵ�
		l->next = a;//l->nextָ���¿ռ�
		scanf_s("%d", &x);//�����µ���ֵx
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
		cout << "����" << b << "�ڱ�" << "��" << i << "λ" << endl;
	}
	else {
		cout << "�������ݲ�����" << endl;
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
		cout << "��" << a << "λ���ݵ�ֵΪ" << b->data<<endl;
	}
	else {
		cout << "��λ�ò�����"<< endl;
	}

	return;
}

void charu(linklist& l, int n, int m) {
	linklist b = l;
	int i = 0;
	int ii = chang(l);
	if (m > ii + 1||m<=0) {
		cout << "����λ�ò�����" << endl;
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
		cout << "ɾ����λ�ò�����" << endl;
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
	linklist a;//����ָ�����lnode����ָ��a����ʱa�����ݲ����Ϸ���
	chushi(a);//��ʼ��a��Ϊa����һ����ַ����aָ��Ľṹ���ݣ�struct londe�ͣ���next��ΪNULL
	tail(a);
	shuchu(a);
	int i=chang(a);
	cout << "�����Ϊ" << i << endl;
	chazhi(a, 99);
	chawei(a, 1);
	charu(a, 999,4);//�ڵ��ĸ�λ�ò��� 999
	shuchu(a);
	shanchu(a, 2);//ɾ���ڶ���λ�õ�����
	shuchu(a);
	return 0;
}