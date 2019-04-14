//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "BinaryNodeTree.h"  // ADT binary tree operations
#include <iostream>
#include <string>

using namespace std;

void display(string& anItem)
{
   cout << "Displaying item - " << anItem << endl;
}  // end display

void check(bool success)
{
   if (success)
      cout << "Done." << endl;
   else
      cout << " Entry not in tree." << endl;
}  // end check

int main()
{

   BinaryTreeInterface<string>* tree1 = new BinaryNodeTree<string>();
   
   tree1->add("10");
   tree1->add("20");
   tree1->add("30");
   tree1->add("40");
   tree1->add("50");
   tree1->add("60");
   tree1->add("70");
   tree1->add("80");
   
   cout<<"Nodes Added: 10 20 40 70 60 30 50 80\n";
   cout<<"inorder traverse";
   tree1->inorderTraverse(display);
   
      tree1 = new BinaryNodeTree<string>();
   tree1->add("10");
   tree1->add("20");
   tree1->add("30");
   tree1->add("40");
   tree1->add("50");
   tree1->add("60");
   tree1->add("70");
   tree1->add("80");
   
   cout<<"Nodes Added: 10 20 40 70 60 30 50 80\n";
   cout<<"inorder traverse";
   tree1->inorderTraverse(display);

   tree1 = new BinaryNodeTree<string>();
   tree1->add("10");
   tree1->add("20");
   tree1->add("30");
   tree1->add("40");
   tree1->add("50");
   tree1->add("60");
   tree1->add("70");
   tree1->add("80");
   
   cout<<"Nodes Added: 10 20 40 70 60 30 50 80\n";
   cout<<"inorder traverse";
   tree1->inorderTraverse(display);

   return 0;
}  // end main

/* SAMPLE OUTPUT
BinaryNodeTree$ ./a.out
Nodes Added: 10 20 40 70 60 30 50 80
inorder traverseDisplaying item - 30
Displaying item - 70
Displaying item - 60
Displaying item - 10
Displaying item - 50
Displaying item - 80
Displaying item - 20
Displaying item - 40
Nodes Added: 10 20 40 70 60 30 50 80
inorder traverseDisplaying item - 60
Displaying item - 80
Displaying item - 10
Displaying item - 70
Displaying item - 50
Displaying item - 40
Displaying item - 20
Displaying item - 30
Nodes Added: 10 20 40 70 60 30 50 80
inorder traverseDisplaying item - 20
Displaying item - 50
Displaying item - 10
Displaying item - 60
Displaying item - 70
Displaying item - 30
Displaying item - 80
Displaying item - 40
 */
