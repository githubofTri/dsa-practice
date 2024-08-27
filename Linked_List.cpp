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

// //thêm node vào danh sách
// Node* headInsert(Node* head, int valueToInsert){
//   Node* nodeToInsert = new Node(valueToInsert);
//   nodeToInsert->next = head;
//   return nodeToInsert;
// }

// // thêm node vào cuối dánh sách
// Node* tailInsert(Node* head, int valueToInsert){
//   Node* temp = head;
//   while(temp->next != nullptr){
//     temp = temp->next;
//   }
//   Node* nodeToInsert = new Node(valueToInsert);
//   temp->next = nodeToInsert;
//   return head;
// }

// // thêm node vào vị trí khác đầu và cuối 
// Node* atIndexInsert(Node* head, int index, int valueToInsert){
//   Node* nodeToInsert = new Node(valueToInsert);
//   int movingIndex = 0;
//   Node* temp = head;
//   while(movingIndex != index-1 && temp != nullptr){
//     temp = temp->next;
//     movingIndex++;
//   }
//   nodeToInsert->next = temp->next;
//   temp->next = nodeToInsert;
//   return head;
// }


// //đổi val của node từ a thành giá trị b 
// Node* convertNode(Node *head, int targetNumber, int numberToConvert){
//   Node *temp = head;
//   while(temp != nullptr){
//     if(temp->val == targetNumber){
//       temp->val = numberToConvert;
//     }
//     temp = temp->next;  
//   }
//   return head;
// }

// xóa phần tử ở đầu 
Node* headRemove(Node* head){
  Node* temp = new Node(0);
  temp = head->next;
  delete head;
  return temp;
}

// xóa phần tử ở cuối danh sách 
Node* tailRemove(Node* head){
  Node* temp = head;
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  delete temp->next;
  temp->next = NULL;
  return head;
}

// xóa phần tử tại vị trí khác đầu cuối 
Node* indexRemove(Node* head, int index){
  int movingIndex = 0;
  Node* container = new Node(0);
  Node* temp = head;
  while(movingIndex != index-1 && temp->next != NULL){
    temp = temp->next;
    movingIndex++;
  }
  container = temp->next->next;
  delete temp->next;
  temp->next = container;
  return head;
}

int main(){
 int n, x, k;
 cin >> n;
 cin >> x;
 Node* head = new Node(x);
 Node* temp = head;
 for(int i = 1; i < n; i++){
   cin >> x;
   temp = addNode(temp, x);
 }
 
// //doi gia tri
// cin >> k;
// cin >> l;
// head = convertNode(head, k, l);
 
 
// // chèn 
//   cin >> k >> l;
//   if(k == 0){
//     head = headInsert(head, l);
//   }else if(k == n){
//     head = tailInsert(head, l);
//   }else head = atIndexInsert(head, k, l);
  
  // xóa dữ liệu
  cin >> k;
  if(k == 0){
    head = headRemove(head);
  }else if(k == n-1){
    tailRemove(head);
  }else head = indexRemove(head, k);
 
 
 //in
 print(head);
 
 return 0;
}