//
// Created by ongel on 10/3/2017.
//

#include "DLinkedBag.h"
#include "DoublyNode.h"

template<class ItemType>
DLinkedBag<ItemType>::DLinkedBag() : headPtr(NULL), itemCount(0) {}


template<class ItemType>
DLinkedBag<ItemType>::~DLinkedBag() {
    clear();
}

template<class ItemType>
int DLinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<class ItemType>
bool DLinkedBag<ItemType>::isEmpty() const {
    return (itemCount == 0);
}

template<class ItemType>
bool DLinkedBag<ItemType>::add(const ItemType &newEntry) {
    DoublyNode<ItemType>* newNodePtr = new DoublyNode<ItemType>();

    newNodePtr->setItem(newEntry);
    newNodePtr->setNext(headPtr);
    newNodePtr->setPrev(NULL);

    headPtr = newNodePtr;
    itemCount++;

    return true;
} // end add

template<class ItemType>
bool DLinkedBag<ItemType>::remove(const ItemType &anEntry) {
    DoublyNode<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != NULL);
    if (canRemoveItem)
    {
        // Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());

        // Delete first node
        DoublyNode<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(NULL);
        delete nodeToDeletePtr;
        nodeToDeletePtr = NULL;

        itemCount--;
    }

    return canRemoveItem;
}

template<class ItemType>
void DLinkedBag<ItemType>::clear() {
    DoublyNode<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != NULL)
    {
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(NULL);
        delete nodeToDeletePtr;

        nodeToDeletePtr = headPtr;
    }  // end while
    // headPtr is NULL; nodeToDeletePtr is NULL

    itemCount = 0;
}

template<class ItemType>
bool DLinkedBag<ItemType>::contains(const ItemType &anEntry) const {
    return (getPointerTo(anEntry) != NULL);
}

template<class ItemType>
int DLinkedBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    int frequency = 0;
    int counter = 0;
    DoublyNode<ItemType>* curPtr = headPtr;
    while ((curPtr != NULL) && (counter < itemCount))
    {
        if (anEntry == curPtr->getItem())
        {
            frequency++;
        } // end if

        counter++;
        curPtr = curPtr->getNext();
    } // end while

    return frequency;
}

template<class ItemType>
vector<ItemType> DLinkedBag<ItemType>::toVector() const {
    vector<ItemType> bagContents;
    DoublyNode<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != NULL) && (counter < itemCount))
    {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    }  // end while

    return bagContents;
}

template<class ItemType>
DoublyNode<ItemType>* DLinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
    bool found = false;
    DoublyNode<ItemType>* curPtr = headPtr;

    while (!found && (curPtr != NULL))
    {
        if (anEntry == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    } // end while

    return curPtr;
} // end getPointerTo
