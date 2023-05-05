#include <string>
#include <iostream>
using namespace std;

struct NodeType;

class RSPType
{
public:
  RSPType(int N);     
  ~RSPType();    
  bool IsCompleted() const;
  int  LengthIs() const;
  void MakeEmpty();
  void InsertItem(string A,  string B); 
  void ResetList();
  void GetNextItem(string& A, string& B);
  void Print();

private:
  NodeType* listData;
  int length;
  NodeType* currentPos;
  int n_count;
  int m_count;
  int A_win_num;
  int B_win_num;
};

struct NodeType
{
    NodeType* next;
    string A;
    string B;
};