/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   queue.h
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on March 17, 2019, 9:24 PM
 */

#ifndef QUEUE_H
#define QUEUE_H
#define SIZE 10

class queue {
private:
    int *arr; // array to store queue elements
    int capacity; // maximum capacity of the queue
    int front; // front points to front element in the queue (if any)
    int rear; // rear points to last element in the queue
    int count; // current size of the queue

public:
    queue(int size = SIZE); // constructor

    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

#endif /* QUEUE_H */

