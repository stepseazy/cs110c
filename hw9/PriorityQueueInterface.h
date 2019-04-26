/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PriorityQueueInterface.h
 * Author: Hendrick Brutsaert
 *
 * Created on April 23, 2019, 8:39 PM
 */

#ifndef PRIORITYQUEUEINTERFACE_H
#define PRIORITYQUEUEINTERFACE_H

template <class ItemType>
class PriorityQueueInterface {
public:
    virtual bool isEmpty() const=0;
    virtual bool add(const ItemType& newEntry)=0;
    virtual bool remove()=0;
    virtual ItemType peek() const=0;
};

#endif /* PRIORITYQUEUEINTERFACE_H */

