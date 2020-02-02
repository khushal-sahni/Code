
#include <iostream>
#include <unordered_set>
using namespace std;
class Node{
public:
  int data;
  Node* next;
};
int detectloop(Node *head){
  unordered_set <Node*> x;
  Node *node = head;
  while(node != NULL){
    if(x.find(node) == x.end()) x.insert(node);
    else return 1;
    node = node->next;
  }
  return 0;
  //Another method called turtle hare method
  Node *hare = head, *turtle = head;
  while(hare->next != NULL && hare->next->next != NULL){
    hare = hare->next->next;
    turtle = turtle->next;
    if(hare == turtle) return 1;
  }
  return 0;
}
int main(){
  Node *head = new Node();
  head->data = 7;
  Node *first = new Node(), *second = new Node(), *third = new Node(), *fourth = new Node();
  first->data = 58;
  head->next = first;
  second->data = 36;
  first->next = second;
  third->data = 34;
  second->next = third;
  fourth->data = 16;
  third->next = fourth;
  fourth->next = third;
  cout <<"Answer is " <<detectloop(head);
}
