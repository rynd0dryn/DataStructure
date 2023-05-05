#include "ItemType.h"
#include <iostream>

using namespace std;

template <class ItemType>
struct NodeType{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
class UnsortedType{
public:
    UnsortedType();
    ~UnsortedType();
    bool IsFull();
    bool IsEmpty();
    int LengthIs();
    void MakeEmpty();
    void InsertItem(ItemType newItem);
    void DeleteItem(ItemType item);
    void RetrieveItem(ItemType& item, bool found);
    void GetNextItem(ItemType& item);
    void ResetList();
    void MergeList(UnsortedType<ItemType>& other,UnsortedType<ItemType>& result);
    void DeleteItem1(ItemType item);
    void PrintReverse();
private:
    NodeType<ItemType>* listData;
    NodeType<ItemType>* currentPos;
    int length;
};

template<class ItemType>
UnsortedType<ItemType>::UnsortedType() {
    length = 0;
    listData = NULL;
}
template<class ItemType>
UnsortedType<ItemType>::~UnsortedType(){
    MakeEmpty();
};

template<class ItemType>
int UnsortedType<ItemType>::LengthIs() {
    return length;
}

template<class ItemType>
bool UnsortedType<ItemType>::IsFull() {
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
bool UnsortedType<ItemType>::IsEmpty() {
    return (listData = NULL);
}

template<class ItemType>
void UnsortedType<ItemType>::MakeEmpty() {
    NodeType<ItemType>* tempPtr;
    while(listData != NULL){
        tempPtr = listData;
        listData = listData -> next;
        delete tempPtr;
    }
    length = 0;
}

template<class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType &item, bool found) {
    NodeType<ItemType>* location;
    location = listData;
    found = false;
    bool moreToSearch = (location != NULL);     //리스트 한 바퀴만 돌자

    while(!found && moreToSearch){
        if(item == location -> info){
            found = true;
            item = location->info;
        }
        else{
            location = location -> next;
            moreToSearch = (location != NULL);
        }
    }
}

template<class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType newItem){
    NodeType<ItemType>* location;
    location = new NodeType<ItemType>;
    location -> info = newItem;
    location -> next = listData;
    listData = location;
    length++;
}

template<class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item){
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;
    if(location -> info == item){
        tempLocation = location;
        location = location -> next;
    }
    else{
        while(!(item == (location -> next) -> info)){
            location = location -> next;
        }
        tempLocation = location -> next;
        location -> next = (location -> next) -> next;
    }
    delete tempLocation;
    length--;
}

template<class ItemType>
void UnsortedType<ItemType>::ResetList() {
    currentPos = NULL;
}

template<class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType &item) {
    if (currentPos == NULL){
        item = listData -> info;
    }
    else {
        currentPos = currentPos -> next;
        item = currentPos->info;
    }
}

template<class ItemType>
void UnsortedType<ItemType>::MergeList(UnsortedType<ItemType> &other, UnsortedType<ItemType> &result) {

}

template <class ItemType>                                   //리스트 내 item이 없어도 에러나지 않게.
void UnsortedType<ItemType>::DeleteItem1(ItemType item) {
    NodeType<ItemType>* location;
    NodeType<ItemType>* predLoc;
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);

    while(moreToSearch){
        if(item == listData -> info){
            predLoc = listData;
            listData = listData -> next;
            delete predLoc;
            length--;
        }
        else{
            if(!(item == (location -> next) -> info)){
                location = location -> next;
                moreToSearch = (location != NULL);
            }
            else{
                predLoc = location -> next;
                location -> next = (location -> next) -> next;
                delete predLoc;
                length--;
            }
        }
    }
}

template <class ItemType>                                   
void UnsortedType<ItemType>::PrintReverse() {
    ItemType item;
    currentPos = listData;
    for(int i = length-1; i > -1; i--){
        for(int j = 0; j < i; j++){
            currentPos = currentPos -> next;
        }
        item = currentPos -> info;
        cout << item << " ";
        currentPos = listData;
    }
}


