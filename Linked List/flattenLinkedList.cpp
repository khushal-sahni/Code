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

// Another way to do this


Node *merge(Node *a,Node *b)
{
if(a==NULL)
return b;
if(b==NULL)
return a;
Node *r;
if(a->data<b->data)
{
    r=a;
    r->bottom=merge(a->bottom,b);
}
else
{
    r=b;
    r->bottom=merge(b->bottom,a);
}
return r;
}
Node *flatten(Node *root)
{
if(root==NULL||root->next==NULL)
return root;
return merge(root,flatten(root->next));
// Your code here
}
