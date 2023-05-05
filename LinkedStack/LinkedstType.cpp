
#include "LinkedstType.h"
#include <iostream>
using namespace std;

StackType::StackType() {
    topPtr = NULL;
}

//copy Constructor
StackType::StackType(const StackType& stack){
    NodeType* ptr1;
    NodeType* ptr2;

    if(stack.topPtr == NULL){
        topPtr = NULL;
    }
    else{
        topPtr = new NodeType;
        topPtr -> info = stack.topPtr -> info;
        ptr1 = stack.topPtr -> next;
        ptr2 = topPtr;
        while(ptr1 != NULL){
            ptr2 -> next = new NodeType;
            ptr2 = ptr2 -> next;
            ptr2 -> info = ptr1 -> info;
            ptr1 = ptr1 -> next;
        }
        ptr2 -> next = NULL;
    }
}

StackType::~StackType() {         //로컬 스택 변수가 scope 나가면 topPtr은 해제되는데
    NodeType* tempPtr;             // topPtr이 가리키고 있던 노드는 남아있어서 해줘야함.
    while(topPtr != NULL){
        tempPtr = topPtr;
        topPtr = topPtr -> next;
        delete tempPtr;
    }
}

StackType& StackType::operator=(const StackType& other) {
    // 자기 자신과의 대입일 경우 바로 리턴
    if (this == &other) {
        return *this;
    }
    // 이전 스택의 모든 요소를 삭제
    while (!IsEmpty()) {
        Pop();
    }

    NodeType* otherCurrent = other.topPtr;
    NodeType* lastNode = NULL;
    while (otherCurrent != NULL) {
        ItemType item = otherCurrent->info;
        NodeType* newNode = new NodeType;
        newNode->info = item;
        newNode->next = NULL;
        if (lastNode == NULL) {
            topPtr = newNode;
        } else {
            lastNode->next = newNode;
        }
        lastNode = newNode;
        otherCurrent = otherCurrent->next;
    }
    // 대입한 스택을 반환
    return *this;
}


bool StackType::IsFull(){
    NodeType* location;
    try{
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc exception){
        return true;
    }
}

bool StackType::IsEmpty(){
    return topPtr == NULL;
}

void StackType::Push(ItemType newItem){
    if (IsFull()){
        throw FullStack();
    }
    else{
        NodeType* location;
        location = new NodeType;
        location -> info = newItem;
        location -> next = topPtr;
        topPtr = location;
    }
}

void StackType::Pop(){
    if(IsEmpty()){
        throw EmptyStack();
    }
    else{
        NodeType* tempPtr;
        tempPtr = new NodeType;
        tempPtr = topPtr;
        topPtr = topPtr -> next;
        delete tempPtr;
    }
}

ItemType StackType::Top(){
    if(IsEmpty()){
        throw EmptyStack();
    }
    else{
        return topPtr -> info;
    }
}

void StackType::ReplaceItem(ItemType oldItem, ItemType newItem) {
    NodeType* location = topPtr;
    while(location != NULL){
        if(location -> info == oldItem){
            location -> info = newItem;
            location = location -> next;
        }
        else{
            location = location -> next;
        }
    }
}

void StackType::Print(){
    NodeType* currentPos = topPtr;
    while(currentPos != NULL){
        cout << currentPos -> info << " ";
        currentPos = currentPos -> next;
    }

}