#include <iostream>
#include <set>
using namespace std;
class Node{
public:
  int data;
  Node* next;
  Node* bottom;
};

Node* flatten(Node* root){
  multiset <int> x;
  Node* prev = root, *node;
  while(prev != NULL){
    node = prev;
    while(node != NULL){
      x.insert(node->data);
      node = node->bottom;
    }
    prev = prev->next;
  }
  node = root;
  node->data = *x.begin();
  for(auto i = ++x.begin(); i != x.end(); i++){
    Node* nodee = new Node();
    nodee->data = *i;
    node->bottom = nodee;
    node = nodee;
  }
  node->bottom = NULL;
  return root;
}
