#include <iostream>
using namespace std;
class FullQueue{};
class EmptyQueue{};

template <class ItemType>
class QueType{
public:
    QueType();
    QueType(int max);
    ~QueType();
    void MakeEmpty();
    bool IsFull();
    bool IsEmpty();
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);   //지우고 item에 지운 값 저장
    void ReplaceItem(ItemType oldItem, ItemType newItem); //2번
    bool Identical(QueType queue); // 3번
    int Length();  //4번

private:
    int front;
    int rear;
    int maxQue;
    ItemType* items;
};


template <class ItemType>
QueType<ItemType>::QueType(){
    front = maxQue -1;
    rear = maxQue -1;
    maxQue = 501;
    items = new ItemType[maxQue];
}

template <class ItemType>
QueType<ItemType>::QueType(int max){
    maxQue = max + 1;   //reserved area
    front = maxQue -1;
    rear = maxQue -1;
    items = new ItemType[maxQue];
}

template <class ItemType>
QueType<ItemType>::~QueType(){
    delete[] items;
}

template <class ItemType>
void QueType<ItemType>::MakeEmpty() {
    front = maxQue-1;
    rear = maxQue-1;
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty(){
    return (front == rear);
}

template <class ItemType>
bool QueType<ItemType>::IsFull(){
    return (front == (rear+1)%maxQue);
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem){
    if(IsFull()){
        throw FullQueue();
    }
    else {
        rear = (rear + 1) % maxQue;
        items[rear] = newItem;
    }
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType &item){
    front = (front+1)%maxQue;
    item = items[front];    //원래 front에 있는 값 지운거. items[front] = reserved area
}


template <class ItemType>
void QueType<ItemType>::ReplaceItem(ItemType oldItem, ItemType newItem) {
    for(int i = 0; i < maxQue; i++){
        if(items[i] == oldItem){
            items[i] = newItem;
        }
    }
}

template <class ItemType>
bool QueType<ItemType>::Identical(QueType queue) {
    int length = (rear+1)%maxQue - (front+1)%maxQue;
    int item;
    if(queue.Length() != length){
        cout << "0";
        return false;
    }
    else{
        for(int i = 0; i < length; i++) {
            queue.Dequeue(item);
            if(items[i] != item){
                cout << "1";
                return false;
            }
        }
        cout << "2";
        return true;
    }
}

template <class ItemType>
int QueType<ItemType>::Length(){
    int length = (rear+1)%maxQue - (front+1)%maxQue;
    return length;
}




