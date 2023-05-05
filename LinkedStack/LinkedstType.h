
typedef int ItemType;

class FullStack{};
class EmptyStack{};

struct NodeType;
class StackType{
public:
    StackType();
    StackType(const StackType& anotherStack);
    ~StackType();
    StackType& operator= (const StackType& other);
    bool IsEmpty();
    bool IsFull();
    void Push(ItemType newItem);
    void Pop();
    ItemType Top();
    void ReplaceItem(ItemType oldItem, ItemType newItem);
    void Print();

private:
    NodeType* topPtr;
};

struct NodeType{
    ItemType info;
    NodeType* next;
};

