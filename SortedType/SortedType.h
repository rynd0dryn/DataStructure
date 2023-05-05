#include "ItemType.h"
#include <iostream>
const int MAX_ITEMS = 200;
using namespace std;

class SortedType{
public:
    SortedType();
    bool IsFull();
    int LengthIs();
    void InsertItem(ItemType newItem);
    void DeleteItem(ItemType item);
    void RetrieveItem(ItemType& item, bool found);
    void GetNextItem(ItemType& item);
    void ResetList();
private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};

