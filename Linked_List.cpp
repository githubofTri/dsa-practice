#include<iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node(int val): val (val), next(nullptr) {};
};

//duyệt danh sách
void print(Node* head){
  Node* temp = head; 
  while(temp != NULL){
    cout << temp->val << " "; 
    temp = temp->next;
  }
}

//thêm node vào đuôi
Node* addNode(Node *node, int x){
  Node *nodeToAdd = new Node(x);
  node->next = nodeToAdd;
  return nodeToAdd;
}

//đổi val của node từ a thành giá trị b 
Node* convertNode(Node *head, int targetNumber, int numberToConvert){
  Node *temp = head;
  while(temp != nullptr){
    if(temp->val == targetNumber){
      temp->val = numberToConvert;
    }
    temp = temp->next;  
  }
  return head;
}

int main(){
 int n, x, k, l;
 cin >> n;
 cin >> x;
 Node* head = new Node(x);
 Node* temp = head;
 for(int i = 1; i < n; i++){
   cin >> x;
   temp = addNode(temp, x);
 }
 
 //doi gia tri
 cin >> k;
 cin >> l;
 head = convertNode(head, k, l);
 
 //in
 print(head);
 
 return 0;
}