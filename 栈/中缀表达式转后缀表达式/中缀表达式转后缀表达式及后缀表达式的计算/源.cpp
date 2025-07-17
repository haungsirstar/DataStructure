//中缀表达式转后缀表达式

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
    int i = 0;//中缀
    stack aa;//栈
    initstack(aa);
    char m;//用于记录出栈元素
    while (i < a.length()) {
        
        if (a[i] ==  '(' ) {
            push(aa, a[i]);
            i++;
        }//左括号直接入栈

        else if (a[i] == ')') {
            pop(aa, m);
            while(m!='('){
                
                b+= m;
                pop(aa, m);
                i++;
            }//出栈元素为（时循环结束
            
            
        }

        else if (a[i] == '/' || a[i] == '*'||a[i] == '+' || a[i] == '-') {
            while (peek(aa, m)&&m!='(' &&priority(m)>=priority(a[i])) {//栈顶不为空不为（且优先级大于等于中缀当前
                pop(aa, m);
                b+= m;
                
            }
            push(aa, a[i]);
            i++;
        }

        else {//操作数直接进入后缀表达式
        
         b += a[i];
         i++;
        }
        

    }
    while (pop(aa, m)) {
        if (m != '(') b += m;
    }//最后所有栈内符号出栈

    
    cout << a << "的后缀表达式为" << b<<endl;
    return b;
}



int main() {
    string a = "2+(2-1)*3";
    string b = midtoback(a);

	return 0;
}