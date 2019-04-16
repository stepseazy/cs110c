
/*
 * File:   main.cpp
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on March 9, 2019, 11:13 AM
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <map>
#include "stack.cpp"

using namespace std;

bool isOperator(char ch) {
    static const string ops = "*/-+";
    return (ops.find(ch) < ops.length());
}

bool isValidInfix(string s) {
    stack<char> operandStack;
    stack<char> parensStack;
    char ch;
    for (int i = 0; i < s.length(); i++) {
        ch = s[i];
        if (ch == '(') {
            parensStack.push(ch);
        } else if (ch == ')') {
            if (parensStack.isEmpty()) {
                return false;
            } else if (s[i - 1] == '(') {
            }
            parensStack.pop();
        } else if (isdigit(ch)) {
            //cant be preceded by ) or digit
            if (i > 0) {
                if (s[i - 1] == ')' || isdigit(s[i - 1])) {
                    return false;
                }
            }
            //cant be followed by ( or digit
            if (i < s.length() - 1) {
                if (s[i + 1] == '(' || isdigit(s[i + 1])) {
                    return false;
                }
            }
        } else if (isOperator(ch)) {
            //can't be last char
            if (i == s.length() - 1) {
                return false;
            }
            //can't be preceded by operator
            if (isOperator(s[i - 1])) {
                return false;
            }
            //can't be followed by operator
            if (isOperator(s[i + 1])) {
                return false;
            }
        } else {//any other character
            return false;
        }
    }
    return parensStack.isEmpty();
}

string infixToPostFix(string infix) {
    if (!isValidInfix(infix)) {
        throw invalid_argument("invalid infix");
    }

    stack<char> aStack;
    int i = 0;
    string postFixExp;
    map<char, int> precedence = {
        {'*', 2},
        {'/', 2},
        {'+', 1},
        {'-', 1}
    };
    char ch;
    while (i < infix.length()) {
        ch = infix[i];
        if (isdigit(ch)) {
            postFixExp += ch;
        } else if (infix[i] == '(') {
            aStack.push(ch);
        } else if (isOperator(ch)) {
            while (
                    !aStack.isEmpty()
                    && aStack.peek() != '('
                    && precedence[ch] <= precedence[aStack.peek()]) {

                postFixExp += aStack.pop();
            }
            aStack.push(ch);
        } else if (ch == ')') {
            while (aStack.peek() != '(') {
                postFixExp += aStack.pop();
            }
            aStack.pop();
        }
        i++;
    }
    while (!aStack.isEmpty()) {

        postFixExp += aStack.pop();
    }
    return postFixExp;
}

double calcPostfix(string s) {
    stack<double> stack;
    char ch;
    char op1, op2;
    double operand1, operand2;
    for (int i = 0; i < s.length(); i++) {
        ch = s[i];
        if (isdigit(ch)) {
            stack.push((double) ch - 48);
        } else if (isOperator(ch)) {
            operand2 = stack.pop();
            operand1 = stack.pop();
            switch (ch) {
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '+':
                    stack.push(operand1 + operand2);
                    break;
            }
        }
    }
    return stack.peek();
}

bool getContinue() {
    char ans;
    cout << "continue (y/n): ";
    cin>>ans;
    return (ans == 'y');
}

int main(int argc, char** argv) {
    do {
        string infix, postfix;
        cout << "Enter infix expression" << endl;
        cin>>infix;
        try {
            postfix = infixToPostFix(infix);
        } catch (invalid_argument logErr) {
            cout << "failed to create postfix because " << logErr.what() << endl;
            continue;
        }
        cout << "postfix of " << infix << " is: " << postfix << endl;
        double result = calcPostfix(postfix);
        cout << "result: " << result << endl;
    } while (getContinue() == true);
    return 0;
}

/*
output:

[hbrutsae@hills brutsaert_hendrik_hw6]$ ./a.out
Enter infix expression
1+2-3
postfix of 1+2-3 is: 12+3-
result: 0
continue (y/n): y
Enter infix expression
-1-2
postfix of -1-2 is: 1-2-
result: -3
continue (y/n): y
Enter infix expression
(-1-2)-3
postfix of (-1-2)-3 is: 1-2-3-
result: -6
continue (y/n): y
Enter infix expression
(1*2-4)+5
postfix of (1*2-4)+5 is: 12*4-5+
result: 3
continue (y/n): y
Enter infix expression
1++3
failed to create postfix because invalid infix
continue (y/n): y
Enter infix expression
12=^H
failed to create postfix because invalid infix
continue (y/n): y
Enter infix expression
a_^H
failed to create postfix because invalid infix
continue (y/n): y
Enter infix expression
a+2
failed to create postfix because invalid infix
continue (y/n): y
Enter infix expression
12-4
failed to create postfix because invalid infix
continue (y/n): y
Enter infix expression
)3-2
failed to create postfix because invalid infix
continue (y/n): y
Enter infix expression
((-4)
failed to create postfix because invalid infix
continue (y/n): n
[hbrutsae@hills brutsaert_hendrik_hw6]$ 
*/