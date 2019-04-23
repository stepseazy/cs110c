/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ArrayMaxHeap.h
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on April 22, 2019, 4:28 PM
 */

#ifndef ARRAYMAXHEAP_H
#define ARRAYMAXHEAP_H

#include "HeapInterface.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType> {
private:
    static const int ROOT_INDEX = 0; // Helps with readability
    static const int DEFAULT_CAPACITY = 21; // Small capacity to test for a full heap
    ItemType* items; // Array of heap items
    int itemCount; // Current count of heap items
    int maxItems; // Maximum capacity of the heap
    // ---------------------------------------------------------------------
    // Most of the private utility methods use an array index as a parameter
    // and in calculations. This should be safe, even though the array is an
    // implementation detail, since the methods are private.
    // ---------------------------------------------------------------------
    // Returns the array index of the left child (if it exists).
    int getLeftChildIndex(const int nodeIndex) const;
    // Returns the array index of the right child (if it exists).
    int getRightChildIndex(int nodeIndex) const;
    // Returns the array index of the parent node.
    int getParentIndex(int nodeIndex) const;
    // Tests whether this node is a leaf.
    bool isLeaf(int nodeIndex) const;
    // Converts a semiheap to a heap.
    void heapRebuild(int subTreeRootIndex);
    // Creates a heap from an unordered array.
    void heapCreate();
    void swap(int index1, int index2);
public:
    ArrayMaxHeap();
    ArrayMaxHeap(const ItemType someArray[], const int arraySize);
    virtual ~ArrayMaxHeap();
    // HeapInterface Public Methods:
    bool isEmpty() const;
    int getNumberOfNodes() const;
    int getHeight() const;
    ItemType peekTop() const throw (PrecondViolatedExcep);
    bool add(const ItemType& newData);
    bool remove();
    void clear();

};

#endif /* ARRAYMAXHEAP_H */

