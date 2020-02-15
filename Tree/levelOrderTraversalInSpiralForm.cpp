#include <iostream>
#include <deque>
using namespace std;

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
void printSpiral(Node* root){
  if(root == NULL) return;
  deque <Node *> q;
  Node* node; bool forward = false;
  q.push_back(NULL);
  q.push_back(root);

  while(q.size() > 1){
    if(q.front() == NULL && forward == true) forward = false;
    if(q.back() == NULL && forward == false) forward = true;

      if(forward){
        node = q.front();
        cout << (node->data) << " ";
        if(node->left != NULL) q.push_back(node->left);
        if(node->right != NULL) q.push_back(node->right);
        q.pop_front();
      }
      else{
        node = q.back();
        cout << (node->data) << " ";
        if(node->right != NULL) q.push_front(node->right);
        if(node->left != NULL) q.push_front(node->left);
        q.pop_back();
      }

  }
}
