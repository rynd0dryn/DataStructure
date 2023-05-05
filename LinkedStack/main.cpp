#include <iostream>
#include "LinkedstType.h"
using namespace std;

void ReplaceItem(StackType& st, ItemType oldItem, ItemType newItem){
    StackType tempStack;
    int item;
    while(!st.IsEmpty()) {
        item = st.Top();
        st.Pop();
        if(item == oldItem){
            tempStack.Push(newItem);
        }
        else{
            tempStack.Push(item);
        }
    }
    while(!tempStack.IsEmpty()){
        item = tempStack.Top();
        tempStack.Pop();
        st.Push(item);
    }

}


int main() {
    StackType stA;
    stA.Push(1);
    stA.Push(2);
    cout << "A : ";
    stA.Print();
    cout << endl;

    stA.Pop();
    stA.Push(3);
    stA.Push(4);
    cout << "A : ";
    stA.Print();
    cout << endl;

    StackType stB(stA);
    stA.Pop();
    stA.Pop();
    cout << "A : ";
    stA.Print();
    cout << endl;
    cout << "B : ";
    stB.Print();
    cout << endl;

    return 0;



}
