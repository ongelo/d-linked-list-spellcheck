//
// Created by ongel on 10/3/2017.
//

#include "DoublyNode.h"
#include <cstddef>

template<class ItemType>
DoublyNode<ItemType>::DoublyNode() {

} // end default constructor

template<class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& anItem) {
    item = anItem;
}

template<class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& anItem, DoublyNode<ItemType>* nextNodePtr,
           DoublyNode<ItemType>* prevNodePtr) {
    item = anItem;
    next = nextNodePtr;
    prev = prevNodePtr;
}

template<class ItemType>
void DoublyNode<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<class ItemType>
void DoublyNode<ItemType>::setNext(DoublyNode<ItemType>* nextNodePtr) {
    next = nextNodePtr;
}

template<class ItemType>
void DoublyNode<ItemType>::setPrev(DoublyNode<ItemType>* prevNodePtr) {
    prev = prevNodePtr;
}

template<class ItemType>
ItemType DoublyNode<ItemType>::getItem() const {
    return item;
}

template<class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getNext() const {
    return next;
}

template<class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getPrev() const {
    return prev;
}