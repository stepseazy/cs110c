/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   queue.cpp
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on March 17, 2019, 8:35 PM
 */

#include "q.h"
#include <iostream>
using namespace std;

template<class ItemType>
q<ItemType>::q(int size) {
    arr = new ItemType[size + 1];
    capacity = size;
    front = capacity;
    back = capacity;
};

template<class ItemType>
ItemType q< ItemType>::dequeue() {
    if (isEmpty()) {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    ItemType last = peek();
    cout << "Removing " << arr[(front + 1 + capacity + 1) % (capacity + 1)] << endl;

    front = (front + 1) % (capacity + 1);

    return last;
}

template<class ItemType>
void q< ItemType>::enqueue(ItemType item) {
    if (isFull()) {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << '\n';

    back = (back + 1) % (capacity + 1);
    arr[back] = item;
}

template<class ItemType>
ItemType q<ItemType>::peek() {
    if (isEmpty()) {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[(front + 1 + capacity + 1) % (capacity + 1)];
}

template<class ItemType>
int q< ItemType>::size() {
    return ((back - front + capacity + 1) % (capacity + 1));
}

template<class ItemType>
bool q< ItemType>::isEmpty() {
    return (size() == 0);
}

template<class ItemType>
bool q< ItemType>::isFull() {
    return (front == ((back + 1) % (capacity + 1)));
}

template<class ItemType>
void q< ItemType>::print() {
    for (int index = 0; index < capacity + 1; index++) {
        cout << arr[index] << " ";
    }
    cout << "front " << front << " back " << back << " size " << size() << endl;
}
