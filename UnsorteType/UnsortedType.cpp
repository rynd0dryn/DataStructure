#include <iostream>
#include <fstream>
#include "UnsortedType.h"
using namespace std;

UnsortedType::UnsortedType() {
    length = 0;
}

int UnsortedType::LengthIs() {
    return length;
}

bool UnsortedType::IsFull() {
    return (length == MAX_ITEMS);
}

void UnsortedType::RetrieveItem(ItemType &item, bool found) {
    bool moreToSearch;
    int location = 0;
    found = false;
    moreToSearch = (location < length);     //리스트 한 바퀴만 돌자

    while(!found && moreToSearch){
        switch(item.ComparedTo(info[location])){     //item이랑 리스트 원소랑 비교
            case Less:
            case Greater:
                location++;
                moreToSearch = (location < length);
                break;
            case Equal:
                found = true;
                item = info[location];
                break;
        }
    }
}

void UnsortedType::InsertItem(ItemType newItem){
    info[length] = newItem;
    length++;
}

void UnsortedType::DeleteItem(ItemType item){
    int location = 0;
    while(item.ComparedTo(info[location]) != Equal){
        location++;
    }
    info[location] = info[length-1];
    length--;

}

void UnsortedType::ResetList() {
    currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType &item) {
    currentPos++;
    item = info[currentPos];
}