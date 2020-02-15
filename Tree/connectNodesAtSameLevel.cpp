#include <iostream>
#include <queue>
using namespace std;
struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
};
void connect(Node *p)
{
   if(p == NULL) return;
   queue <Node*> q;
   Node *prev = NULL, *node;
   q.push(p);
   q.push(NULL);
   while(q.size() > 1){
     if(q.front() == NULL){
       if(prev != NULL) prev->nextRight = NULL;
       prev = NULL;
       q.pop();
       q.push(NULL);
     }
     else{
       node = q.front();
       if(prev != NULL) prev->nextRight = node;
       if(node->left != NULL) q.push(node->left);
       if(node->right != NULL) q.push(node->right);
       prev = node;
       q.pop();
     }
   }
}
