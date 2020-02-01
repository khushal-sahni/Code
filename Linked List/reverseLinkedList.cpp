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

Node* reverseList(Node *head){
  Node *first = head, *second, *third;
  if(first == NULL) return NULL;
  if(first->next == NULL) return first;
  second = first->next; first->next = NULL;
  while(second->next != NULL){
      third = second->next;
      second->next = first;
      first = second;
      second = third;
  }
  second->next = first;
  return head=second;
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
    cout << "\nNow reversing the list\n";
    printList(reverseList(head));
  }
}
