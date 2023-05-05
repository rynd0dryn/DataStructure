
#include "MaxItem.h"
class FullStack{};
class EmptyStack{};

template <class ItemType>
class StackTemplate{
public:
    StackTemplate();
//    void MakeEmpty();
    bool IsFull();
    bool IsEmpty();
    void Push(ItemType newItem);
    void Pop();
    ItemType Top();
private:
    int top;
    ItemType items[100];
};

template <class ItemType>
StackTemplate<ItemType>::StackTemplate(){
    top = -1;
}

//template <class ItemType>
//void StackTemplate<ItemType>::MakeEmpty() {
//    top = -1;
//}

template <class ItemType>
bool StackTemplate<ItemType>::IsEmpty() {
    return (top == -1);
}

template <class ItemType>
bool StackTemplate<ItemType>::IsFull() {
    return (top == MAX_ITEMS-1);    //length를 따로 설정할까 했는데 top이 그 역할 해주네
}

template <class ItemType>
void StackTemplate<ItemType>::Push(ItemType newItem){
    if(IsFull()){
        throw FullStack();
    }
    else {
        top++;
        items[top] = newItem;
    }
}

template <class ItemType>
void StackTemplate<ItemType>::Pop() {
    if(IsEmpty()){
        throw EmptyStack();
    }
    else {
        top--;
    }
}

template <class ItemType>
ItemType StackTemplate<ItemType>::Top(){
    if(IsEmpty()){
        throw EmptyStack();
    }
    else{
        return items[top];
    }
}