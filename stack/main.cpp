#include <iostream>
//#include "StackType.h"
#include "StackTemplate.h"
using namespace std;
//
//void CopyStack(StackType stackA, StackType& stackB){
//    StackType stackC;
//    int temp;
//    while(!stackA.IsEmpty()){
//        temp = stackA.Top();
//        stackA.Pop();
//        stackC.Push(temp);
//    }
//    while(!stackC.IsEmpty()){
//        temp = stackC.Top();
//        stackC.Pop();
//        stackB.Push(temp);
//    }
//}
//
//void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem){
//    int temp;
//    StackType tempStack;
//    while(!stack.IsEmpty()){
//        temp = stack.Top();
//        stack.Pop();
//        if(temp == oldItem){
//            temp = newItem;
//        }
//        tempStack.Push(temp);
//    }
//    while(!tempStack.IsEmpty()){
//        int item = tempStack.Top();
//        tempStack.Pop();
//        stack.Push(item);
//    }
//}


int main() {
    string in;
    StackTemplate<char> st;
    int noperand = 0;
    getline(cin,in);

    for(int i = 0; i < in.length(); i++){
        string s = "";
        if(isdigit(in[i])) {
            while (isdigit(in[i])) {
                s += in[i];
                ++i;
            }
            --i;
            if (noperand == 0) {
                cout << s << ' ';
                ++noperand;
            } else {
                cout << s << ' ';
                cout << st.Top() << ' ';
                st.Pop();
            }
        }
        else if(in[i] == '+' || in[i] == '-' || in[i] =='*'||in[i] == '/'){
            st.Push(in[i]);
        }
    }
    cout << endl;
}
