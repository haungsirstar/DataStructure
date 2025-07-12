//定长顺序表的初始化，插入删除，按值查找，按位查找

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MaxSize 50
typedef struct {
	int data[MaxSize];
	int chang;
} shunxu;//定义了结构体shunxu

void printlist(shunxu& L) {
	for (int i = 0; i < L.chang; i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
}

void shuru(shunxu& L,int list[], int n) {
	
	if (n > MaxSize) {
		cout << "最大长度超出容量" << endl;
		n = MaxSize;//长度设为50，后面的不要了
	}
	for (int i = 0; i < MaxSize&&i<n; i++) {
		L.data[i] = list[i];//数组不能直接相等，需要依次赋值
	}
	L.chang = n;
}

void chushi(shunxu& L) {
	L.chang = 0;//设定目前长度为0
}

void charu(shunxu& L,int a,int b) {
	if (a > MaxSize||a<1||a>L.chang+1) {
		cout << "插入位置无效" << endl;
		return;
	}
	if (L.chang == MaxSize) {
		cout << "已满无法插入" << endl;
		return;
	}
	for (int i = L.chang;i>=a;i--) {
		L.data[i] = L.data[i - 1];//从最后一个值开始赋值，值为前一个值
		
	}
	L.data[a - 1] = b;//插入位置等于插入值
	L.chang++;
}
void chazhi(shunxu&L, int a) {
	for (int i = 0; i < L.chang; i++) {
		if (L.data[i] == a) {
			cout << "值为 " << a << " 的数据在第 " << i + 1 << " 位" << endl;
			return;
		}
	}
	cout << "查找数据不存在" << endl;
}

void chawei(shunxu& L, int a) {
	if (a<1 || a>L.chang) {
		cout << "查找的位置不存在" << endl;
		return;
	}
	cout << "第" << a << "位的数值为" << L.data[a - 1] << endl;

}
void shanchu(shunxu& L,int a) {
	if (a<1 || a>L.chang) {
		cout << "该位置不存在" << endl;
		return;
	}
	for (int i = a - 1; i < L.chang-1; i++) {
		L.data[i] = L.data[i + 1];
	}
	L.chang--;
}
int main() {
	shunxu a;//创建了名为a的shunxu结构体
	chushi(a); //初始化a
	int list[] = {1, 2, 3, 5, 6, 7, 2, 1, 3};
	shuru(a, list, 9);
	printlist(a);
	int c = 3, d = 100;
	charu(a, c, d);//在第c个位置插入值为d的数据
	printlist(a);
	chawei(a, 5);
	shanchu(a, 4);// 删除第四个位置
	printlist(a);
}