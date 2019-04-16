/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Sorter.h
 * Author: Rik
 *
 * Created on February 7, 2019, 12:41 PM
 */

#ifndef SORTER_H
#define SORTER_H
#include <string>
using namespace std;

enum sortAlgo {
    BUBBLE, QUICK, COUNTING
};

struct Result {
    int index;
    int count;
};

class Sorter {
private:
    int arraySize;
    int *array = nullptr;
    int *unsortedArray = nullptr;
    int sizes[3] = {8, 32, 128};
    double results[3][3][3];
    int getRand(int min, int max);
public:
    Sorter(int size);
    ~Sorter();
    void initArray();
    void initResults();
    void resetArray();
    void runAlgos();
    void printResults();
    int sort(sortAlgo s);

    void swap(int index1, int index2);
    int bubbleSort();
    int quickSort();
    int quickSort(int left, int right);
    Result partition(int left, int right, int pivot);
    int countingSort();
    void print();
    void SetArraySize(int arraySize);
    int GetArraySize() const;

};

#endif /* SORTER_H */

