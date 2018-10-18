//
// Created by ongel on 10/3/2017.
//

#ifndef DLINKEDBAG_H
#define DLINKEDBAG_H

#include "DoublyNode.h"
#include "BagInterface.h"

template <class ItemType>
class DLinkedBag : public BagInterface<ItemType> {
private:
    DoublyNode <ItemType> *headPtr; // Pointer to first node
    int itemCount;

    DoublyNode <ItemType> *getPointerTo(const ItemType &target) const;

public:
    DLinkedBag();
    virtual ~DLinkedBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType &newEntry);
    bool remove(const ItemType &anEntry);
    void clear();
    bool contains(const ItemType &anEntry) const;
    int getFrequencyOf(const ItemType &anEntry) const;
    vector <ItemType> toVector() const;

}; // end DLinkedBag

#include "DLinkedBag.cpp"

#endif //DLINKEDBAG_H
