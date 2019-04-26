/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heap_PriorityQueue.h
 * Author: Hendrick Brutsaert
 *
 * Created on April 23, 2019, 8:43 PM
 */

#ifndef HEAP_PRIORITYQUEUE_H
#define HEAP_PRIORITYQUEUE_H

#include "ArrayMaxHeap.cpp"
#include "PriorityQueueInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class Heap_PriorityQueue : public PriorityQueueInterface<ItemType>, private ArrayMaxHeap<ItemType> {
public:
    Heap_PriorityQueue();
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove();
    ItemType peek() const throw(PrecondViolatedExcep);
private:

};

#endif /* HEAP_PRIORITYQUEUE_H */

