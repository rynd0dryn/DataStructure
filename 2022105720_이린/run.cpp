#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "RSPType.h"
using namespace std;


string num2RSP(int num)
{
    string rsp;

    switch (num) {
        case 0:
            rsp = "rock";
            break;
        case 1:
            rsp = "scissors";
            break;
        case 2:
            rsp = "paper";
            break;
        default:
            cout << "wrong" <<endl;
    }

    return rsp;
}


int main()
{

    int N;

    cin >> N;

    RSPType games(N);

    srand((unsigned int)time(NULL));

    while(!games.IsCompleted())
    {
        int digit_A,digit_B;
        digit_A = rand()%3;
        digit_B = rand()%3;
        string A = num2RSP(digit_A);
        string B = num2RSP(digit_B);

        games.InsertItem(A, B);
    }

    games.Print();


    return 0;
}