//��׺���ʽת��׺���ʽ

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
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

int priority(char a) {
    if (a == '+' || a == '-')
    {
        return 1;
    }
    if (a == '*' || a == '/')
    {
        return 2;
    }
    else {
        return 0;
    }

}


string midtoback(string a) {
    string b;
    int i = 0;//��׺
    stack aa;//ջ
    initstack(aa);
    char m;//���ڼ�¼��ջԪ��
    while (i < a.length()) {
        
        if (a[i] ==  '(' ) {
            push(aa, a[i]);
            i++;
        }//������ֱ����ջ

        else if (a[i] == ')') {
            pop(aa, m);
            while(m!='('){
                
                b+= m;
                pop(aa, m);
                i++;
            }//��ջԪ��Ϊ��ʱѭ������
            
            
        }

        else if (a[i] == '/' || a[i] == '*'||a[i] == '+' || a[i] == '-') {
            while (peek(aa, m)&&m!='(' &&priority(m)>=priority(a[i])) {//ջ����Ϊ�ղ�Ϊ�������ȼ����ڵ�����׺��ǰ
                pop(aa, m);
                b+= m;
                
            }
            push(aa, a[i]);
            i++;
        }

        else {//������ֱ�ӽ����׺���ʽ
        
         b += a[i];
         i++;
        }
        

    }
    while (pop(aa, m)) {
        if (m != '(') b += m;
    }//�������ջ�ڷ��ų�ջ

    
    cout << a << "�ĺ�׺���ʽΪ" << b<<endl;
    return b;
}



int main() {
    string a = "2+(2-1)*3";
    string b = midtoback(a);

	return 0;
}