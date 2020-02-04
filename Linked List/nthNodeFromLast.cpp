#include <iostream>
int getNthFromLast(Node *head, int n){
  Node *node = head;
  int length = 0;
  while(node != NULL){
    length++;
    node = node->next;
  }
  node = head;
  int index = 0;
  while(node != NULL){
    if(index == (length-n)) return node->data;
    node = node->next;
    index++;
  }
  return -1;
}
