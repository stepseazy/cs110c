/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on April 22, 2019, 4:27 PM
 */

#include <cstdlib>
#include <string>
#include "priorityItem.h"
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    priorityItem p1(1, "item1");
    priorityItem p2(2, "item2");
    p1.toString();
    p2.toString();
    cout << "p1<p2" << (p1 < p2) << endl;
    return 0;
}

