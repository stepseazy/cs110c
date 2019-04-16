/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   stack.h
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on March 9, 2019, 11:14 AM
 */

#ifndef STACK_H
#define STACK_H
#define MAX 1000

template<class ItemType>
class stack {
    int top;
public:
    ItemType a[MAX]; //Maximum size of Stack

    stack() {
        top = -1;
    }
    bool push(ItemType x);
    ItemType pop();
    bool isEmpty();
    ItemType peek();
};

#endif /* STACK_H */

