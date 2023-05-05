#include <iostream>
#include <string>
using namespace std;

struct ItemType{
    string item;
    ItemType *next;
    ItemType *back;
};

class NStack{
    ItemType *data;
public:
    NStack();
    NStack(NStack&);
    ~NStack();
    bool nmPush(int,int,string);
    bool nmPop(int,int,string&);
    void print(string);
};


NStack::NStack() {
   data = NULL;
}

NStack::NStack(NStack& another){
    data = NULL;
    NStack temp;
    ItemType* ptr = another.data;
    while (ptr != NULL) {
        temp.nmPush(0, 0, ptr->item);
        ptr = ptr->next;
    }
    ptr = temp.data;
    while ( ptr!= NULL) {
        nmPush(0, 0, ptr->item);
        ptr = ptr->next;
    }
}

NStack::~NStack() {
    ItemType* ptr = data;
    while (ptr != NULL) {
        ItemType* location = ptr;
        ptr = ptr->next;
        delete location;
    }
}

bool NStack::nmPush(int n, int m, string x){
    int length = 0;
    int loc = n - m;
    ItemType* currentPos = data;
    ItemType* location = new ItemType;
    location -> item = x;
    location -> next = NULL;
    location -> back = NULL;

    while(currentPos != NULL){         //길이재기
        length++;
        currentPos = currentPos -> next;
    }

    if (length < n || loc < 0) {
        return false;
    }
    if(loc==0){
        if (length == 0) {        //insert into empty list
            data = location;
        }
        else {
            data->back = location;
            location->next = data;
            data = location;
        }
    }
    else if (loc == length) {      //insert at the end of the list
        currentPos = data;
        for (int i = 1; i < length; i++) {
            currentPos = currentPos->next;
        }
        currentPos->next = location;
        location->back = currentPos;
    }else{
        currentPos = data;
        for (int i = 0; i < n - m; i++) {
            currentPos = currentPos->next;
        }
        location->next = currentPos;
        location->back = currentPos->back;
        currentPos->back->next = location;
        currentPos->back = location;
    }
    return true;
}

bool NStack::nmPop(int n, int m, string &x) {
    int length = 0;
    int loc = n - m;
    ItemType* del;
    ItemType *currentPos = data;

    if (currentPos == NULL) return false;     //비어있는 리스트(삭제 x)
    while (currentPos != NULL) {               //길이 재기
        length++;
        currentPos = currentPos->next;
    }
    if (length <= n || loc < 0) {
        return false;
    } else {
        if (loc == 0) {                   //이동 없이 삭제
            del = data;
            x = del -> item;
            data = data->next;
            data -> back = NULL;
            delete del;
        } else {
            if (loc == length-1) {          //맨 뒤 삭제
                currentPos = data;
                for (int i = 1; i < loc; i++) {
                    currentPos = currentPos->next;
                }
                del = currentPos;
                x = del -> item;

                currentPos = currentPos -> next;
                currentPos -> back = NULL;
                delete del;
            } else {                        //(n-m)만큼 이동 후 삭제
                currentPos = data;
                for(int i = 0; i < loc; i++){
                    currentPos = currentPos -> next;
                }
                del = currentPos;
                x = del -> item;
                currentPos->back->next = currentPos->next;
                currentPos->next->back = currentPos->back;
                delete del;
            }
        }
    }
    return true;
}

void NStack::print(string x) {
    cout << x << ": ";
    ItemType* currentPos = data;

    while(currentPos != NULL){
        cout << currentPos -> item << " ";
        currentPos  = currentPos -> next;
    }
    cout << endl;
}
