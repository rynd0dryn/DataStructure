#include <iostream>
#include "SortedType.h"
using namespace std;

template <class ItemType>
void MergeList(SortedType<ItemType> &l_a, SortedType<ItemType> &l_b,SortedType<ItemType>& result) {
    ItemType item;
    l_a.ResetList();
    l_b.ResetList();
    for(int i = 0; i < l_a.length; i++){
        l_a.GetNextItem(item);
        result.InsertItem(item);
    }
    for(int i = 0; i < l_b; i++){
        l_b.GetNextItem(item);
        result.InsertItem(item);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
