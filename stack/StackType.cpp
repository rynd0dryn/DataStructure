#include "StackType.h"
#include <iostream>
using namespace std;

StackType::StackType() {
    top = -1;
}

void StackType::MakeEmpty() {
    top = -1;
}

bool StackType::IsEmpty() {
    return (top == -1);
}

bool StackType::IsFull() {
    return (top == MAX_ITEMS-1);    //length를 따로 설정할까 했는데 top이 그 역할 해주네
}

void StackType::Push(ItemType newItem){
    if(IsFull()){
        throw FullStack();
    }
    else {
        top++;
        items[top] = newItem;
    }
}

void StackType::Pop(){
    if(IsEmpty()){
        throw EmptyStack();
    }
    else {
        top--;
    }
}

ItemType StackType::Top(){
    if(IsEmpty()){
        throw EmptyStack();
    }
    else{
        return items[top];
    }
}

void StackType::ReplaceItem(int oldItem, int newItem) {
    for(int i = 0; i <= top; i++){
        if(items[i] == oldItem){
            items[i] = newItem;
        }
    }
}


