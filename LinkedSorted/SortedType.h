#include "ItemType.h"
#include <iostream>

using namespace std;
template <class ItemType>
struct NodeType{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
class SortedType{
public:
    SortedType();
    ~SortedType();
    bool IsFull();
    int LengthIs();
    void MakeEmpty();
    void InsertItem(ItemType newItem);
    void DeleteItem(ItemType item);
    void RetrieveItem(ItemType& item, bool found);
    void GetNextItem(ItemType& item);
    void ResetList();
    void MergeList(SortedType<ItemType>& other, SortedType<ItemType>& result);

private:
    NodeType<ItemType>* listData;
    NodeType<ItemType>* currentPos;
    int length;
};

