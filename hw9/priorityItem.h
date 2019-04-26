/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   priorityItem.h
 * Author: hendrik.brutsaert@cs110c.ccsf
 *
 * Created on April 22, 2019, 9:20 PM
 */

#ifndef PRIORITYITEM_H
#define PRIORITYITEM_H
#include <string>
#include <iostream>

using namespace std;

class priorityItem {
private:
    int priority;
    string description;
public:

    priorityItem(){
        priority=0;
        description="no description";
    }
    
    priorityItem(int p, string d) {
        priority = p;
        description = d;
    };

    priorityItem(const priorityItem& orig) {
        priority = orig.priority;
        description = orig.description;
    }

    bool operator>(priorityItem item2) {
        return (priority > item2.priority);
    };

    bool operator<(priorityItem item2) {
        return (priority < item2.priority);
    };

    string toString() {
        return ("(priority "+to_string(priority)+") "+description+"\n");
    }
};

#endif /* PRIORITYITEM_H */

