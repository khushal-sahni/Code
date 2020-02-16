#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node
{
	int key;
	struct Node* left, *right;
};

Node* createNode(){
  Node* node = new Node();
  node->key = NULL;
  node->left = NULL;
  node->right = NULL;
}

void func(Node* node, bool &allNull, queue <Node *> &q){
  if(node->left != NULL){
    q.push(node->left);
    allNull = false;
  }
  else q.push(createNode());
  if(node->right != NULL){
    q.push(node->right);
    allNull = false;
  }
  else q.push(createNode());
}

bool isSymmetric(struct Node* root)
{
	if(root == NULL) return true;
  queue <Node *> q;
  stack <int> s;
  Node * node;
  int i, level = 2;
  bool allNull = false;

  func(root, allNull, q);

  while(!allNull){
    allNull = true;
    for(i = 0; i < level/2; i++){
      node = q.front();
      s.push(node->key);
      func(node, allNull, q);
      q.pop();
    }
    for(i = 0; i < level/2; i++){
      node = q.front();
      if(node->key != s.top()) return false;
      s.pop();
      func(node, allNull, q);
      q.pop();
    }
    level *= 2;
  }
  return true;
}
///////////////////ANOTHER SOLUTION/////////////////////////////
bool find(Node *l,Node *r)
{
if((l&& !r) || (l && !r)) return 0;
if(!l && !r) return 1;
if(l->key != r->key) return 0;

return (find(l->left,r->right)&&find(l->right,r->left));
}
bool isSymmetric(struct Node* root)
{
if(root) return find(root->left,root->right);
return NULL;
}
