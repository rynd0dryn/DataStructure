
#include "SortedType.h"
#include <iostream>
#include <fstream>
using namespace std;

SortedType::SortedType() {
    length = 0;
}

int SortedType::LengthIs() {
    return length;
}

bool SortedType::IsFull() {
    return (length == MAX_ITEMS);
}

void SortedType::RetrieveItem(ItemType &item, bool found) {
   int midPoint;
   int first = 0;
   int last = length-1;
   bool moreToSearch = (first <= last);
   found = false;

   while(!found && moreToSearch){
       midPoint = (first + last)/2;
       switch(item.ComparedTo(info[midPoint])){
           case Less:
               last = midPoint -1;
               moreToSearch = (first <= last);
               break;
           case Equal:
               found = true;
               item = info[midPoint];
               break;
           case Greater:
               first = midPoint +1;
               moreToSearch = (first <= last);
               break;
       }
   }
}

void SortedType::InsertItem(ItemType newItem){
    int location = 0;
    bool moreToSearch = (location < length);
    while(moreToSearch) {
        switch (newItem.ComparedTo(info[location])) {
            case Less:
                moreToSearch = false;
                break;
            case Equal:
                break;
            case Greater:
                location++;
                moreToSearch = (location < length);
                break;
        }
    }
    for(int index = length; index > location; index--){
        info[index] = info[index-1];
    }
    info[location] = newItem;
    length++;
}

void SortedType::DeleteItem(ItemType item){
    int location = 0;
    while(item.ComparedTo(info[location]) != Equal){
        location++;
    }
    for(int index = location+1; index < length; i++){
        info[index-1] = info[index];
    }
    length--;
}

void SortedType::ResetList() {
    currentPos = -1;
}

void SortedType::GetNextItem(ItemType &item) {
    currentPos++;
    item = info[currentPos];
}