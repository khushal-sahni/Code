#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node* func(Node *node, bool whichSide){
  if(node == NULL) return NULL;

  Node* leftNode = func(node->left, false);
  if(leftNode != NULL) leftNode->right = node;
  node->left = leftNode;

  Node* rightNode = func(node->right, true);
  node->right = rightNode;
  if(rightNode != NULL) rightNode->left = node;

  if(!whichSide){
    while(node->right != NULL) node = node->right;
    return node;
  }
  else{
    while(node->left != NULL) node = node->left;
    return node;
  }
}

void bToDLL(Node *root, Node **head_ref)
{
  *head_ref = func(root, true);
}
