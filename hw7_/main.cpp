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
#include "stack.h"
#include "queue.h"

using namespace std;

#define SIZE 10

// Class for queue

class q {
    int *arr; // array to store queue elements
    int capacity; // maximum capacity of the queue
    int front; // front points to front element in the queue (if any)
    int rear; // rear points to last element in the queue
    int count; // current size of the queue

public:
    q(int size = SIZE); // constructor

    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

#include <iostream>
using namespace std;

q::q(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

void q::dequeue() {
    if (isEmpty()) {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << arr[front] << '\n';

    front = (front + 1) % capacity;
    count--;
}

void q::enqueue(int item) {
    if (isFull()) {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << '\n';

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

int q::peek() {
    if (isEmpty()) {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

int q::size() {
    return count;
}

bool q::isEmpty() {
    return (size() == 0);
}

bool q::isFull() {
    return (size() == capacity);
}

int main(int argc, char** argv) {
    // create a queue of capacity 5
    q q(5);

    q.enqueue(1);
    q.print();
    q.enqueue(2);
    q.print();
    q.enqueue(3);
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(4);
    q.dequeue();
    q.enqueue(6);
    q.dequeue();
    q.enqueue(8);
    q.dequeue();
    q.enqueue(10);
    cout << "Front element is: " << q.peek() << endl;
    q.dequeue();

    q.enqueue(4);

    cout << "Queue size is " << q.size() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(4);
    if (q.isEmpty())
        cout << "Queue Is Empty\n";
    else
        cout << "Queue Is Not Empty\n";

    return 0;
}

