#include <iostream>
#include "NStack.h"

void myFunc(NStack pStack){
    string myStr;

    pStack.print("MyFunc");
    pStack.nmPop(0,0,myStr);
    cout  << "MyFunc:(0,0) Popped" << myStr << endl;
    pStack.nmPop(3,0,myStr);
    cout  << "MyFunc:(3,0) Popped" << myStr << endl;
    pStack.print("MyFunc");
    pStack.nmPop(2,1,myStr);
    cout  << "MyFunc:(2,1) Popped" << myStr << endl;
    pStack.print("MyFunc");

}

int main(){
    NStack myStack;
    string myStr;

    myStack.nmPush(0,0,"ABC");
    myStack.nmPush(0,0,"DEF");
    myStack.nmPush(1,0,"abc");
    myStack.nmPush(3,0,"123");
    myStack.nmPush(3,1,"456");
    myStack.nmPush(8,7,"777");
    myStack.nmPush(0,0,"XYZ");
    myStack.nmPush(5,2,"888");
    myStack.print("Main");
    myFunc(myStack);
    myStack.print("Main");
    myStack.nmPop(0,0,myStr);
    cout  << "MyFunc:(0,0) Popped" << myStr << endl;
    myStack.nmPop(0,0,myStr);
    cout  << "MyFunc:(0,0) Popped" << myStr << endl;
    myStack.print("Main");
    myStack.nmPop(2,0,myStr);
    cout  << "MyFunc:(2,0) Popped" << myStr << endl;
    myStack.nmPop(2,1,myStr);
    cout  << "MyFunc:(2,1) Popped" << myStr << endl;
    myStack.print("Main");

    return 0;
}