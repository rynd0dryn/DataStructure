
enum RelationType {Less,Equal,Greater};
#include <fstream>

class ItemType{
public:
    ItemType();
    RelationType ComparedTo(ItemType otherItem);
    void Print(std::ostream& out);
    void Initialize(int number);
private:
    int value;
};
