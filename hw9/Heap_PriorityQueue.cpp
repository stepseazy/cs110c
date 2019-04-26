/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heap_PriorityQueue.cpp
 * Author: Hendrick Brutsaert
 * 
 * Created on April 23, 2019, 8:43 PM
 */

#include "Heap_PriorityQueue.h"
#include <iostream>
using namespace std;

template < class ItemType>
Heap_PriorityQueue<ItemType>::Heap_PriorityQueue() {
    ArrayMaxHeap<ItemType>();
}

template < class ItemType>
bool Heap_PriorityQueue<ItemType>::isEmpty() const{
    return ArrayMaxHeap<ItemType>::isEmpty();
}

template < class ItemType>
bool Heap_PriorityQueue<ItemType>::add(const ItemType& newEntry){
    return ArrayMaxHeap<ItemType>::add(newEntry);
}

template < class ItemType>
bool Heap_PriorityQueue<ItemType>::remove(){
    return ArrayMaxHeap<ItemType>::remove();
}

template < class ItemType>
ItemType Heap_PriorityQueue<ItemType>::peek() const throw(PrecondViolatedExcep){
    try{
        return ArrayMaxHeap<ItemType>::peekTop();
    }
    catch(PrecondViolatedExcep e){
        throw PrecondViolatedExcep("Attempted to peek into an empty priority queue.");
    }
    
    
}