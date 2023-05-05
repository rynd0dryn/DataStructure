#include <iostream>
#include "QueType.h"
using namespace std;

template <class ItemType>
void ReplaceItem(QueType<int>& que, ItemType oldItem, ItemType newItem){
    QueType<int> tempQue;
    int item;

    while(!que.IsEmpty()){
        que.Dequeue(item);
        if(item == oldItem){
            item = newItem;
        }
        tempQue.Enqueue(item);
    }
    while(!tempQue.IsEmpty()){
        tempQue.Dequeue(item);
        que.Enqueue(item);
    }
}

template <class ItemType>
bool Identical(QueType<int> que1, QueType<int> que2){
    int item1, item2;
    if(que1.Length() != que2.Length()){
        cout << "0";
        return false;
    }
    else{
        int num = que1.Length();             //for문 돌 때 i < que1.Length()로 하면
        for(int i = 0; i < num; i++) {       //Dequeue 해서 길이가 달라짐. => 미리 따로 빼주자
            que1.Dequeue(item1);
            que2.Dequeue(item2);
            if(item1 != item2) {
                cout << "1";
                return false;
            }
        }
        cout << "2";
        return true;
    }
}

template <class ItemType>
int Length(QueType<int> que){
    QueType<int> que1;
    int length = 0;
    int item;
    while(!que.IsEmpty()){
        length++;
        que.Dequeue(item);
        que1.Enqueue(item);
    }
    while(!que1.IsEmpty()){
        que1.Dequeue(item);
        que.Enqueue(item);
    }
    return length;
}

template <class ItemType>
void MergeQueue(QueType<ItemType> queue1,QueType<ItemType> queue2, QueType<ItemType>& result) {
    ItemType tempItem1, tempItem2;
    while (!queue1.IsEmpty() && !queue2.IsEmpty()) {
        queue1.Dequeue(tempItem1);
        queue2.Dequeue(tempItem2);


        if (tempItem1 > tempItem2) {
            result.Enqueue(tempItem1);
            result.Enqueue(tempItem2);
        } else {
            result.Enqueue(tempItem2);
            result.Enqueue(tempItem1);
        }
    }
    while(queue2.IsEmpty()){
        queue1.Enqueue(tempItem1);
        result.Enqueue(tempItem1);
    }
    while(queue1.IsEmpty()){
        queue2.Dequeue(tempItem2);
        result.Enqueue(tempItem2);
    }
}







int main() {
    QueType<int> que;
    srand(time(0));
    for(int i = 0; i < 10; i++) {
        int item = rand() % 11;
        cout << item << " ";
        que.Enqueue(item);
        que.Dequeue(item);
    }

}
