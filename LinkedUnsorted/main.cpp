#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main(){
    UnsortedType<int> list;
    list.InsertItem(1);
    list.InsertItem(2);
    list.InsertItem(3);
    list.InsertItem(4);
    list.PrintReverse();

}