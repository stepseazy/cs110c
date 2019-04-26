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
#include "Heap_PriorityQueue.cpp"
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    const int NUM_ITEMS=10;
    priorityItem * p = new priorityItem[10];
    
    p[0]=*new priorityItem(4,"joe biden");
    p[1]=*new priorityItem(2,"pete buttigieg");
    p[2]=*new priorityItem(3,"mike pompeo");
    p[3]=*new priorityItem(1,"robert mueller");
    p[4]=*new priorityItem(6,"scott pruitt");
    p[5]=*new priorityItem(1,"rex tillerson");
    p[6]=*new priorityItem(2,"kellyanne conway");
    p[7]=*new priorityItem(3,"sarah sanders");
    p[8]=*new priorityItem(1,"jared kushner");
    p[9]=*new priorityItem(6,"mike huckabee");

    Heap_PriorityQueue<priorityItem>* Q=new Heap_PriorityQueue<priorityItem>();
    
    for(int i=0;i<NUM_ITEMS;i++){
    Q->add(p[i]);
    }    

    priorityItem temp;
    for(int i=0;i<NUM_ITEMS;i++){
        temp=Q->peek();
        cout<<"Now seeing doctor "<<Q->peek().toString();
        Q->remove();
    }   

    delete [] Q;
    delete [] p;
    
    return 0;
}

