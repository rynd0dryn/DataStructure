#include "RSPType.h"

RSPType::RSPType(int N)  
{
  listData = NULL;
  currentPos = NULL;

  length = 0;
  A_win_num = 0;
  B_win_num = 0;
  n_count = N;
  m_count = (N+1)/2;
}

RSPType::~RSPType()
{
  MakeEmpty();
}  

bool RSPType::IsCompleted() const
{
  if(A_win_num == m_count || B_win_num == m_count){   //A나 B가 M번 이기면 종료. (N판 안에 결론 안나면 날 때까지, 결론 나면 바로 종료)
      return true;
  }
  else return false;
}

int RSPType::LengthIs() const
{
  return length;
}

void RSPType::MakeEmpty()
{
    NodeType* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;

}


void RSPType::InsertItem(string A, string B) {
    NodeType *location;
    location = new NodeType;
    location->A = A;
    location->B = B;
    if(A == "rock"){
        if(B == "scissors"){       //A,B 가위바위보 종류에 따라 승리 횟수 업데이트. 무승부면 아무 것도 하지 않는다.
            A_win_num++;
        }
        else if(B == "paper"){
            B_win_num++;
        }
    }
    else if(A == "scissors"){
        if(B == "paper"){
            A_win_num++;
        }
        else if(B == "rock"){
            B_win_num++;
        }
    }
    else if(A == "paper"){
        if(B == "rock"){
            A_win_num++;
        }
        else if(B == "scissors"){
            B_win_num++;
        }
    }
    location -> next = NULL;

    if (listData == NULL) {                       //Insert into an empty list
        listData = location;
    }
    else{
        currentPos = listData;
        for(int i = 1; i < length; i++){
            currentPos = currentPos -> next;
        }
        currentPos -> next = location;
    }
    n_count = n_count;
    length++;
}


void RSPType::ResetList(){
  currentPos = NULL;
}
 
void RSPType::GetNextItem(string& A, string& B)
{
    if(currentPos == NULL){
        A = listData -> A;
        B = listData -> B;
    }
    else{
        currentPos = currentPos -> next;
        A = currentPos -> A;
        B = currentPos -> B;
    }
}

void RSPType::Print()
{
    currentPos = listData;
    for(int i = 0; i < length; i++){
        cout << "A: " << currentPos -> A << " B: " << currentPos -> B << endl;
        currentPos = currentPos->next;
    }


    if(IsCompleted()){
        if(A_win_num == m_count){
            cout << "Result: A Win" << endl;
        }
        if(B_win_num == m_count ){
            cout << "Result: B Win" << endl;
        }
    }
}

