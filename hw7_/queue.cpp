/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   queue.cpp
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on March 17, 2019, 9:24 PM
 */

#include "queue.h"

#include <iostream>
using namespace std;

queue::queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

void queue::dequeue() {
    if (isEmpty()) {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << arr[front] << '\n';

    front = (front + 1) % capacity;
    count--;
}

void queue::enqueue(int item) {
    if (isFull()) {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << '\n';

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

int queue::peek() {
    if (isEmpty()) {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

int queue::size() {
    return count;
}

bool queue::isEmpty() {
    return (size() == 0);
}

bool queue::isFull() {
    return (size() == capacity);
}

