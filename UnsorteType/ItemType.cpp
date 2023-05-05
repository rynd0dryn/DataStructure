#include <iostream>
#include "ItemType.h"
using namespace std;

ItemType::ItemType(){
    value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) {
    if(value < otherItem.value){
        return Less;
    }
    else if(value == otherItem.value){
        return Equal;
    }
    else if(value > otherItem.value){
        return Greater;
    }
}

void ItemType::Initialize(int number) {
    value = number;
}

void ItemType::Print(std::ostream& out) {
    out << value;
}