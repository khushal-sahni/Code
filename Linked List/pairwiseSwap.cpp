#include <iostream>
#include <utility>
class Node{
public:
  int data;
  Node* next;
};
Node* pairWiseSwap(Node* head){
  auto node = head;
  while(node != NULL && node->next != NULL){
    swap(node->data,node->next->data);
    node = node->next->next;
  }
  return head;
}
