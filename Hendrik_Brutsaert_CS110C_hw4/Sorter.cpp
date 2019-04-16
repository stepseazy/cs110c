/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Sorter.cpp
 * Author: Rik
 *
 * Created on February 7, 2019, 12:41 PM
 */

#include "Sorter.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

Sorter::Sorter(int size) {
    arraySize = size;
    initArray();
    initResults();
}

Sorter::~Sorter() {
    delete [] array;
    array = nullptr;
}

int Sorter::sort(sortAlgo s) {
    switch (s) {
        case BUBBLE:
            return bubbleSort();
        case QUICK:
            return quickSort();
        case COUNTING:
            return countingSort();
    }
}

void Sorter::runAlgos() {
    for (int sizeIndex = 0; sizeIndex < 3; sizeIndex++) {
        arraySize = sizes[sizeIndex];
        for (int pass = 0; pass < 3; pass++) {
            initArray();
            for (int algoIndex = 0; algoIndex < 3; algoIndex++) {
                resetArray();
                results[sizeIndex][algoIndex][pass] = sort((sortAlgo) algoIndex);
            }
        }
    }
}

void Sorter::printResults() {
    string algo[3] = {"bubble", "quick", "counting"};
    int sum;
    for (int sizeIndex = 0; sizeIndex < 3; sizeIndex++) {
        for (int algoIndex = 0; algoIndex < 3; algoIndex++) {
            cout << algo[algoIndex] << "-sort " << sizes[sizeIndex] << ": ";
            sum = 0;
            for (int pass = 0; pass < 3; pass++) {
                sum += results[sizeIndex][algoIndex][pass];
                cout << results[sizeIndex][algoIndex][pass] << " ";
            }
            cout << sum / 3.0 << endl;
        }
    }
}

int Sorter::getRand(int min, int max) {
    return rand() % (max + 1 - min) + min;
}

void Sorter::initArray() {
    if (array) {
        delete [] array;
        delete [] unsortedArray;
        array = nullptr;
        unsortedArray = nullptr;
    }
    array = new int[arraySize];
    unsortedArray = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        array[i] = getRand(1, 100);
        unsortedArray[i] = array[i];
    }
}

void Sorter::initResults() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                results[i][j][k] = 0;
}

void Sorter::resetArray() {
    for (int i = 0; i < arraySize; i++) {
        array[i] = unsortedArray[i];
    }
}

void Sorter::swap(int i1, int i2) {
    int temp = array[i1];
    array[i1] = array[i2];
    array[i2] = temp;
}

int Sorter::bubbleSort() {
    bool swapped;
    int accessCount = 0;
    for (int i = 0; i < (arraySize - 1); i++) {
        for (int j = 0; j < (arraySize - 1 - i); j++) {
            if (array[j + 1] < array[j]) {
                accessCount += 2;
                swap(j, j + 1);
                accessCount += 4;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    return accessCount;
}

int Sorter::quickSort() {
    return quickSort(0, arraySize - 1);
}

int Sorter::quickSort(int left, int right) {
    int accessCount = 0;
    if (left >= right) {
        return accessCount;
    }
    int pivot = array[(left + right) / 2];
    accessCount++;

    Result res = partition(left, right, pivot);
    accessCount += res.count;
    accessCount += quickSort(left, res.index - 1);
    accessCount += quickSort(res.index, right);

    return accessCount;
}

Result Sorter::partition(int left, int right, int pivot) {
    int accessCount = 0;
    while (left <= right) {
        while (array[left] < pivot) {
            accessCount++;
            left++;
        }
        while (array[right] > pivot) {
            accessCount++;
            right--;
        }
        if (left <= right) {
            swap(left, right);
            accessCount += 4;
            left++;
            right--;
        }
    }
    Result r = {left, accessCount};
    return r;
}

int Sorter::countingSort() {
    int accessCount = 0;
    int distribution[100] = {};
    for (int i = 0; i < arraySize; i++) {
        distribution[array[i] - 1]++;
        accessCount += 2;
    }
    int counter = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < distribution[i]; j++) {
            array[counter] = i + 1;
            accessCount++;
            counter++;
        }
    }

    return accessCount;
}

void Sorter::print() {
    for (int i = 0; i < arraySize; i++) {
        cout << i << ": " << array[i] << endl;
    }
}

void Sorter::SetArraySize(int arraySize) {
    this->arraySize = arraySize;
}

int Sorter::GetArraySize() const {
    return arraySize;
}


