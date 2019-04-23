/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ArrayMaxHeap.cpp
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on April 22, 2019, 4:28 PM
 */

#include "ArrayMaxHeap.h"

#include <cstdlib>
#include <bits/stdc++.h>

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize) :
itemCount(arraySize), maxItems(2 * arraySize) {
    // Allocate the array
    items = new ItemType[2 * arraySize];
    // Copy given values into the array
    for (int i = 0; i < itemCount; i++)
        items[i] = someArray[i];
    // Reorganize the array into a heap
    heapCreate();
} // end constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() :
itemCount(0), maxItems(DEFAULT_CAPACITY) {
    // Allocate the array
    items = new ItemType[DEFAULT_CAPACITY];
} // end constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap() {
    // Allocate the array
    delete [] items;
} // end constructor

template < class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const {
    return (2 * nodeIndex) + 1;
}

template < class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const {
    return (2 * nodeIndex) + 2;
}

template < class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const {
    return (nodeIndex - 1) / 2;
}

template < class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(const int nodeIndex) const {
    return (getLeftChildIndex(nodeIndex) > itemCount - 1);
}

template < class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int rootIndex) {
    // Recursively trickle the item at index root down to its proper position by
    // swapping it with its larger child, if the child is larger than the item.
    // If the item is at a leaf, nothing needs to be done.
    if (!isLeaf(rootIndex)) {
        // The root must have a left child; assume it is the larger child
        int largerChildIndex = getLeftChildIndex(rootIndex); // Left child index
        int rightChildIndex = getRightChildIndex(rootIndex); // Right child index
        if (rightChildIndex < itemCount) {
            largerChildIndex = (items[rightChildIndex] > items[largerChildIndex ]) ?
                    rightChildIndex : largerChildIndex; // Larger child index
        }
        // If the item in the root is smaller than the item in the larger child, swap items
        if (items[rootIndex] < items[largerChildIndex]) {
            swap(rootIndex, largerChildIndex);
            // Transform the semiheap rooted at largerChildIndex into a heap
            heapRebuild(largerChildIndex);
        }
    }
}

template < class ItemType>
void ArrayMaxHeap<ItemType>::swap(int index1, int index2) {
    ItemType temp = index1;
    index1 = index2;
    index2 = temp;
} // end swap

template < class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate() {
    for (int index = itemCount / 2; index >= 0; index--)
        heapRebuild(index);
} // end heapCreate

template < class ItemType>
bool ArrayMaxHeap<ItemType>::remove() {
    if (isEmpty())
        return false;
    // Copy the item from the last node and place it into the root
    items[ROOT_INDEX] = items[itemCount - 1];
    // Remove the last node
    itemCount--;
    // Transform the semiheap back into a heap
    heapRebuild(ROOT_INDEX);
    return true;
} // end remove

template < class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData) {
    if (itemCount >= maxItems)
        return false;
    // Insert newData into the bottom of the tree
    items[itemCount] = newData;
    // Trickle new item up to the appropriate spot in the tree
    int newDataIndex = itemCount;
    bool inPlace = false;
    while ((newDataIndex > 0) and !inPlace) {
        int parentIndex = getParentIndex(newDataIndex);
        if (items[newDataIndex] < items[parentIndex])
            inPlace = true;
        else {
            swap(newDataIndex, parentIndex);
            newDataIndex = parentIndex;
        }
    }
    itemCount++;
    return true;
} // end remove

template < class ItemType >
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw (PrecondViolatedExcep) {
    if (isEmpty())
        throw PrecondViolatedExcep("Attempted peek into an empty heap.");
    return items[ROOT_INDEX];
} // end peekTop

template < class ItemType >
bool ArrayMaxHeap<ItemType>::isEmpty() const {
    return itemCount == 0;
} // end isEmpty

template < class ItemType >
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const {
    return itemCount;
} // end getNumberOfNodes

template < class ItemType >
int ArrayMaxHeap<ItemType>::getHeight() const {
    return ceil(log2(itemCount + 1));
} // end getHeight

template < class ItemType >
void ArrayMaxHeap<ItemType>::clear() {
    itemCount = 0;
} // end clear