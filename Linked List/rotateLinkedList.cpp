#include <iostream>
using namespace std;
class Node{
public:
  int data;
  Node *next;
};

void printList(Node *head){
  auto node = head;
  while(node != NULL){
    cout << node->data << "\n";
    node = node->next;
  }
  cout << "\n";
}

Node* rotate(Node* head, int k){
  Node *node = head, *startNode;
  int i = 1;
  while((node->next != NULL) && (i < k)){
    node = node->next;
    i++;
  }
  if(node->next != NULL) startNode = node->next;
  else return head;
  node->next = NULL;
  node = startNode;
  while(node->next != NULL){
    node = node->next;
  }
  node->next = head;
  return head=startNode;
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
    cout << "Now rotating linked list \n";
    printList(rotate(head,5));
  }
}
