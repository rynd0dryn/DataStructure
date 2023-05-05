#include "ItemType.h"
#include <iostream>
using namespace std;


class StackType{
public:
    StackType();
    void MakeEmpty();
    bool IsFull();
    bool IsEmpty();
    void Push(ItemType newItem);
    void Pop();
    ItemType Top();
    void ReplaceItem(ItemType oldItem, ItemType newItem);

private:
    int items[MAX_ITEMS];
    ItemType top;
};

