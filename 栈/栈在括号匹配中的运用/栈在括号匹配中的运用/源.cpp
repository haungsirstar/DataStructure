//ջ������ƥ���е�����
//����һ�����ţ��ж��Ƿ�ƥ��ɹ�
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<iostream>
using namespace std;

#define max 50

typedef struct stack {
    char data[max];
    int top;
} stack;

void initstack(stack& s) {
    s.top = -1;
}

bool isempty(stack& s) {
    return s.top == -1;
}

bool push(stack& s, char ch) {
    if (s.top == max - 1) return false;
    s.data[++s.top] = ch;
    return true;
}

bool pop(stack& s, char& ch) {
    if (s.top == -1) return false;
    ch = s.data[s.top--];
    return true;
}

bool peek(stack& s, char& ch) {
    if (s.top == -1) return false;
    ch = s.data[s.top];
    return true;
}

bool isValid(string str) {
    int i = 0;
    stack a;
    initstack (a);
    char n;
    char m;
    while (i < str.length()){
        if (str[i] == '[' || str[i] == '(' || str[i] == '{') {
            push(a, str[i]);
            i++;
        }


        if (str[i] == ']' || str[i] == ')' || str[i] == '}') {
            if (!pop(a,n)) {//�����Ź��࣬��ջʧ��
                cout << str << "ƥ��ʧ��" << endl;
                return false;
            }
            m = str[i];
            i++;//��ջ��i+����
            if ((m == ']' && n == '[') || (m == '}' && n == '{') || (m == ')' && n == '(')) {
                if(i == str.length()) {
                    break;
                }
            }
            else {
                cout << str << "ƥ��ʧ��" << endl;
                return false;
            }
            
        }
        
    }
    if (a.top != -1) {//�����Ź���
        cout << str << "ƥ��ʧ��" << endl;
        return false;
    }

    else {
        cout << str << "ƥ��ɹ�" << endl;
        return true;
    }
    
}

int main() {
    isValid("()");
    isValid("{[()]}");     //  ƥ��ɹ�
    isValid("({[)]}");     //  ��ƥ��
    isValid("()()");       //  ƥ��ɹ�
    isValid("(((()");      //  �����Ŷ���
    isValid("())");        //  �����Ŷ���
    return 0;
}