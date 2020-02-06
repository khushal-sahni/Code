#include <iostream>
class Node{
public:
  int data;
  Node* next;
}
Node* sortedMerge(Node* head1, Node* head2){
  if(head1 == NULL) return head2;
  if(head2 == NULL) return head1;
  Node* q;
  if(head1->data < head2->data){
    q = head1;
    q->next = sortedMerge(head1->next, head2);
  }
  else{
    q = head2;
    q->next = sortedMerge(head1, head2->next);
  }
  return q;
}
