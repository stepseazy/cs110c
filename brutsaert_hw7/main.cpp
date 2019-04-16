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

/*
output:
[hbrutsae@hills brutsaert_hw7]$ ./a.out
testing q
Inserting 1
1 0 0 0 0 0 front 5 back 0 size 1
Inserting 2
1 2 0 0 0 0 front 5 back 1 size 2
Inserting 3
1 2 3 0 0 0 front 5 back 2 size 3
Removing 1
1 2 3 0 0 0 front 0 back 2 size 2
Inserting 4
1 2 3 4 0 0 front 0 back 3 size 3
Removing 2
1 2 3 4 0 0 front 1 back 3 size 2
Inserting 6
1 2 3 4 6 0 front 1 back 4 size 3
Removing 3
1 2 3 4 6 0 front 2 back 4 size 2
Inserting 8
1 2 3 4 6 8 front 2 back 5 size 3
Removing 4
1 2 3 4 6 8 front 3 back 5 size 2
Inserting 10
10 2 3 4 6 8 front 3 back 0 size 3
Removing 6
10 2 3 4 6 8 front 4 back 0 size 2
Inserting 4
10 4 3 4 6 8 front 4 back 1 size 3
Removing 8
10 4 3 4 6 8 front 5 back 1 size 2
Removing 10
10 4 3 4 6 8 front 0 back 1 size 1
Removing 4
10 4 3 4 6 8 front 1 back 1 size 0
Inserting 4
10 4 4 4 6 8 front 1 back 2 size 1
********
0
enter string to check palindrome
raw
Inserting r
Inserting a
Inserting w
Removing r
not a palindrome
continue (y/n)? y
0
enter string to check palindrome
mom
Inserting m
Inserting o
Inserting m
Removing m
Removing o
Removing m
palindrome
continue (y/n)? y
0
enter string to check palindrome
racecar
Inserting r
Inserting a
Inserting c
Inserting e
Inserting c
Inserting a
Inserting r
Removing r
Removing a
Removing c
Removing e
Removing c
Removing a
Removing r
palindrome
continue (y/n)? y
0
enter string to check palindrome
rodrigo
Inserting r
Inserting o
Inserting d
Inserting r
Inserting i
Inserting g
Inserting o
Removing r
not a palindrome
continue (y/n)? n
[hbrutsae@hills brutsaert_hw7]$ 

*/