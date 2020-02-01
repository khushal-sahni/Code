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

Node *reverse(Node *head, int k){
  if(head == NULL || k <= 0) return head;
  Node *current = head;
  Node *next;
  Node *prev = NULL;
  int count = 0;
  while(current && count < k){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
  }
  head->next = reverse(next,k);
  return prev;
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
    cout << "Now reversing with groups \n";
    printList(reverse(head,4));
  }
}
