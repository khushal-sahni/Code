#include <iostream>
using namespace std;
class Node{
public:
  int data;
  Node* next;
};

void printList(Node *head){
  auto node = head;
  while(node != NULL){
    cout << node->data << "\n";
    node = node->next;
  }
  cout << "\n";
}

int getMiddle(Node *head){
  Node* node = head;
  Node* jumpingNode = head;
  while(jumpingNode->next != NULL && jumpingNode->next->next != NULL){
    node = node->next;
    jumpingNode = jumpingNode->next->next;
  }
  if(jumpingNode->next != NULL) node = node->next;
  return node->data;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,data;
    scanf("%d",&n);
    scanf("%d",&data);
    Node *head = new Node();
    head->data = data;
    head->next = NULL;
    Node *prev = head;
    for(int i = 1; i < n; i++){
      Node *newNode = new Node();
      scanf("%d",&data);
      newNode->data = data;
      newNode->next = NULL;
      prev->next = newNode;
      prev = newNode;
    }
    printList(head);
    cout << getMiddle(head);
  }
}
