//’ª‘⁄¿®∫≈∆•≈‰÷–µƒ‘À”√
// ‰»Î“ª¥Æ¿®∫≈£¨≈–∂œ «∑Ò∆•≈‰≥…π¶
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
            if (!pop(a,n)) {//”“¿®∫≈π˝∂‡£¨≥ˆ’ª ß∞‹
                cout << str << "∆•≈‰ ß∞‹" << endl;
                return false;
            }
            m = str[i];
            i++;//≥ˆ’ª∫Ûi+£°£ª
            if ((m == ']' && n == '[') || (m == '}' && n == '{') || (m == ')' && n == '(')) {
                if(i == str.length()) {
                    break;
                }
            }
            else {
                cout << str << "∆•≈‰ ß∞‹" << endl;
                return false;
            }
            
        }
        
    }
    if (a.top != -1) {//◊Û¿®∫≈π˝∂‡
        cout << str << "∆•≈‰ ß∞‹" << endl;
        return false;
    }

    else {
        cout << str << "∆•≈‰≥…π¶" << endl;
        return true;
    }
    
}

int main() {
    isValid("()");
    isValid("{[()]}");     //  ∆•≈‰≥…π¶
    isValid("({[)]}");     //  ≤ª∆•≈‰
    isValid("()()");       //  ∆•≈‰≥…π¶
    isValid("(((()");      //  ◊Û¿®∫≈∂‡”‡
    isValid("())");        //  ”“¿®∫≈∂‡”‡
    return 0;
}