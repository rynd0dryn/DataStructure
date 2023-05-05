
#include "SortedType.h"
#include <iostream>
#include <fstream>
using namespace std;

template <class ItemType>
SortedType<ItemType>::SortedType() {
    length = 0;
    listData = NULL;
}

template <class ItemType>
SortedType<ItemType>::~SortedType() {
    MakeEmpty();
}

template <class ItemType>
int SortedType<ItemType>::LengthIs() {
    return length;
}

template <class ItemType>
bool SortedType<ItemType>::IsFull() {
    NodeType<ItemType>* location;
    try{
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(bad_alloc exception){
        return true;
    }
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty() {
    NodeType<ItemType>* tempPtr;
    while(listData != NULL){
        tempPtr = listData;
        listData = listData -> next;
        delete tempPtr;
    }
}

template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType &item, bool found) {
    NodeType<ItemType>* location;
    location = listData;
    found = false;
    bool moreToSearch = (location != NULL);

    while(!found && moreToSearch){
        if(item < location->info){
            location = location -> next;
        }
        else if(item == location -> info){
            found = true;
            item = location -> info;
        }
        else{
            location = NULL;
        }
    }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType newItem){
    NodeType<ItemType>* newNode;
    NodeType<ItemType>* preLoc;
    NodeType<ItemType>* location;
    bool moreToSearch;

    location = listData;
    preLoc = NULL;
    moreToSearch = (location != NULL);

    while(moreToSearch){
        if(newItem > location -> info){
            preLoc = location;
            location = location -> next;
            moreToSearch = (location != NULL);
        }
        else{
            moreToSearch = false;
        }

        newNode = new NodeType<ItemType>;
        newNode -> info = newItem;
        if(preLoc == NULL){
            newNode -> next = listData;
            listData = newNode;
        }
        else{
            newNode -> next = location;
            preLoc -> next = newNode;
        }
        length++;
    }
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item){
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    if(item == listData -> info){
        tempLocation = listData;
        listData = listData -> next;
    }
    else{
        while(!(item == (location -> next)-> info)){
            tempLocation = location -> next;
            location -> next = (location -> next) -> next;
        }
    }
    delete tempLocation;
    length--;
}

template <class ItemType>
void SortedType<ItemType>::ResetList() {
    currentPos = NULL;
}

template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType &item) {
    if(currentPos == NULL){
        item = listData -> info;
    }
    else{
        currentPos = currentPos -> next;
        item = currentPos -> info;
    }
}

template <class ItemType>
void SortedType<ItemType>::MergeList(SortedType<ItemType>& other, SortedType<ItemType>& result) {
    NodeType<ItemType>* ptr1 = listData;
    NodeType<ItemType>* ptr2 = other.listData;
    ItemType item;
    result.listData = new NodeType<ItemType>;
    result.currentPos = result.listData;
    while (ptr1 != NULL && ptr2 != NULL) {
        result.currentPos->info = min(ptr1->info, ptr2->info);
        if(ptr1->info<ptr2->info){
            ptr1 = ptr1->next;
        }
        else {
            ptr2 = ptr2->next;
        }
        result.length++;
        result.currentPos->next = new NodeType<ItemType>;
        result.currentPos = result.currentPos->next;
    }
    if (ptr1 == NULL && ptr2!=NULL) {
        while (ptr2 != NULL) {
            result.currentPos->info = ptr2->info;
            ptr2 = ptr2->next;
            result.length++;
            result.currentPos->next = new NodeType<ItemType>;
            result.currentPos = result.currentPos->next;
        }
    }
    if (ptr1 != NULL && ptr2 == NULL) {
        while (ptr1 != NULL) {
            result.currentPos->info = ptr1->info;
            ptr1 = ptr1->next;
            result.length++;
            result.currentPos->next = new NodeType<ItemType>;
            result.currentPos = result.currentPos->next;
        }
    }
    result.currentPos->next=NULL;
    result.ResetList();
}