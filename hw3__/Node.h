//Hendrik Brutsaert
//cs110c


#pragma once
template<class ItemType>
class Node
{
private:
	ItemType        item; // A data item
	Node<ItemType>* next;
	Node<ItemType>* prev; // Pointer to next node

public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	void setPrev(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
	Node<ItemType>* getPrev() const;

}; // end Node
