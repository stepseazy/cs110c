/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   queue.h
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on March 17, 2019, 8:35 PM
 */

#ifndef QUEUE_H
#define QUEUE_H

// define default capacity of the queue
#define SIZE 10
// Class for queue

template<class ItemType>
class q {
    ItemType *arr; // array to store queue elements
    int capacity; // maximum capacity of the queue
    int front; // front points to front element in the queue (if any)
    int back; // rear points to last element in the queue

public:

    q(int size = SIZE); // constructor

    ItemType dequeue();
    void enqueue(ItemType x);
    ItemType peek();
    int size();
    bool isEmpty();
    bool isFull();

    void print();

};

#endif /* QUEUE_H */

