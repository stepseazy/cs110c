/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Rik
 *
 * Created on February 7, 2019, 12:39 PM
 */

#include <cstdlib>
#include <iostream>

#include "Sorter.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    Sorter s(8);
    cout << "unsorted array: " << endl;
    s.print();
    s.resetArray();
    s.bubbleSort();
    cout << "bubble sort: " << endl;
    s.print();
    s.resetArray();
    s.quickSort();
    cout << "quick sort: " << endl;
    s.print();
    s.resetArray();
    s.countingSort();
    cout << "counting sort: " << endl;
    s.print();
    cout << "comparison of algos: " << endl;
    s.runAlgos();
    s.printResults();
    return 0;
}

/*
[hbrutsae@hills hw4]$ ./a.out

        unsorted array:
0: 34
1: 44
2: 63
3: 30
4: 1
5: 9
6: 53
7: 57
bubble sort:
0: 1
1: 9
2: 30
3: 34
4: 44
5: 53
6: 57
7: 63
quick sort:
0: 1
1: 9
2: 30
3: 34
4: 44
5: 53
6: 57
7: 63
counting sort:
0: 1
1: 9
2: 30
3: 34
4: 44
5: 53
6: 57
7: 63
comparison of algos:
bubble-sort 8: 96 60 96 84
quick-sort 8: 55 51 56 54
counting-sort 8: 24 24 24 24
bubble-sort 32: 1590 1494 1338 1474
quick-sort 32: 379 335 339 351
counting-sort 32: 96 96 96 96
bubble-sort 128: 23064 23196 24138 23466
quick-sort 128: 1947 1808 1768 1841
counting-sort 128: 384 384 384 384

RUN SUCCESSFUL (total time: 206ms)

 */