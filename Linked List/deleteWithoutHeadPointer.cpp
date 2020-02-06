#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void deleteNode(Node* node){
  while(node->next != NULL && node->next->next != NULL){
    node->data = node->next->data;
    node = node->next;
  }
  if(node->next != NULL) node->data = node->next->data;
  node->next = NULL;
}
