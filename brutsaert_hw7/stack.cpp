/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   stack.cpp
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on March 9, 2019, 11:14 AM
 */

#include "stack.h"
#include <iostream>
using namespace std;

template<class ItemType>
bool stack<ItemType>::push(ItemType x) {
    if (top >= (MAX - 1)) {
        //cout << "Stack Overflow";
        return false;
    } else {
        a[++top] = x;
        return true;
    }
}

template<class ItemType>
ItemType stack<ItemType>::pop() {
    if (top < 0) {
        //cout << "Stack Underflow";
        return 0;
    } else {
        ItemType x = a[top--];
        return x;
    }
}

template<class ItemType>
bool stack<ItemType>::isEmpty() {
    return (top < 0);
}

template<class ItemType>
ItemType stack<ItemType>::peek() {
    return a[top];
}


