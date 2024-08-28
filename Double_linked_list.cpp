// Solve problem
//input n
//output array from n -> 1 -> n 
//using double LL 
#include<iostream>
using namespace std;

struct node{
  int data;
  node* next;
  node* pre;
  node(int data): data (data), pre(nullptr), next(nullptr) {};
};


//them vao dau
node* addHead(node* center, int x){
  node* newNode = new node(x);
  center->pre = newNode;
  newNode->next = center;
  return newNode;
}

// them vao duoi
node* addTail(node* center, int x){
  node* newNode = new node(x);
  center->next = newNode;
  newNode->pre = center;
  return newNode;
}

void print(node* list){
  node* temp = list;
  while(temp != nullptr){
    cout << temp->data << " ";
    temp = temp->next;
  }
}

//tao list 

int main(){
  int n;
  cin >> n;
  node* center = new node(1);
  node* centerHead = center;
  node* centerTail = center;
  for(int i = 2; i <= n; i++){
    centerHead = addHead(centerHead, i);
    centerTail = addTail(centerTail, i);
  }
  
  print(centerHead);
  return 0;
}