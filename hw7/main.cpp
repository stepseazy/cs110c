/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
#include "q.cpp"

using namespace std;

bool checkPalindrome() {
    string palindrome;
    cout << palindrome.length() << endl;

    cout << "enter string to check palindrome" << endl;
    cin>>palindrome;
    q<char> q(palindrome.length());
    stack<char> s;
    if (palindrome.length() == 0) {
        return false;
    }
    for (int i = 0; i < palindrome.length(); i++) {
        q.enqueue(palindrome[i]);
        s.push(palindrome[i]);
    }
    for (int i = 0; i < palindrome.length(); i++) {
        if (s.pop() != q.dequeue()) {
            return false;
        }
    }
    return true;
}

bool getContinue() {
    char c;
    cout << "continue (y/n)? ";
    cin>>c;
    return (c == 'y');
}

int main(int argc, char** argv) {
    // create a queue of capacity 5
    q<int> q(5);

    cout << "testing q" << endl;
    q.enqueue(1);
    q.print();
    q.enqueue(2);
    q.print();
    q.enqueue(3);
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(4);
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(6);
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(8);
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(10);
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(4);
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(4);
    q.print();
    cout << "********" << endl;
    do {
        cout << (checkPalindrome() ? "palindrome" : "not a palindrome") << endl;
    } while (getContinue());
}

