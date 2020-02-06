#include <iostream>
#include <cmath>
class Node{
public:
  int data;
  Node* next;
};
Node* addTwoLists(Node* first, Node* second){
  Node *firstNode = first, *secondNode = second, *node;
  int carry,data;
  Node *head = new Node();
  node = head;
  data = firstNode->data+secondNode->data;
  node->data = data%10;
  carry = data/10;
  firstNode = firstNode->next; secondNode = secondNode->next;
  while(firstNode != NULL && secondNode != NULL){
    Node *newNode = new Node();
    data = firstNode->data+secondNode->data+carry;
    newNode->data = data%10;
    carry = data/10;
    node->next = newNode;
    node = newNode;
    firstNode = firstNode->next;
    secondNode = secondNode->next;
  }
  while(firstNode != NULL){
    Node *newNode = new Node();
    data = firstNode->data+carry;
    newNode->data = data%10;
    carry = data/10;
    node->next = newNode;
    node = newNode;
    firstNode = firstNode->next;
  }
  while(secondNode != NULL){
    Node *newNode = new Node();
    data = secondNode->data+carry;
    newNode->data = data%10;
    carry = data/10;
    node->next = newNode;
    node = newNode;
    secondNode = secondNode->next;
  }
  if(carry > 0){
    Node *newNode = new Node();
    newNode->data = carry;
    node->next = newNode;
    node = newNode;
  }
  node->next = NULL;
  return head;
}
