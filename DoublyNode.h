//
// Created by ongel on 10/3/2017.
//

#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

template<class ItemType>
class DoublyNode {
private:
    ItemType item; // item/data
    DoublyNode<ItemType>* next; // pointer to next node
    DoublyNode<ItemType>* prev; // pointer to previous node
public:
    DoublyNode(); // default constructor
    DoublyNode(const ItemType& anItem);
    DoublyNode(const ItemType& anItem, DoublyNode<ItemType>* nextNodePtr, DoublyNode<ItemType>* prevNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(DoublyNode<ItemType>* nextNodePtr);
    void setPrev(DoublyNode<ItemType>* prevNodePtr);
    ItemType getItem() const;
    DoublyNode* getNext() const;
    DoublyNode* getPrev() const;
}; // end DoublyNode

#include "DoublyNode.cpp"

#endif //DOUBLYNODE_H
