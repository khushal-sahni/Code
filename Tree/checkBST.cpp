#include <iostream>
#include <climits>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
bool issBST(Node *root, int leftLimit, int rightLimit){
  if(root == NULL) return true;
  if(!(root->data > leftLimit && root->data < rightLimit)) return false;
  if(root->left == NULL && root->right == NULL) return true;
  if(root->left == NULL) return issBST(root->right, root->data, rightLimit);
  if(root->right == NULL) return issBST(root->left, leftLimit, root->data);
  return (issBST(root->right, root->data, rightLimit)&&issBST(root->left, leftLimit, root->data));
}
bool isBST(Node *root){
  return issBST(root, INT_MIN, INT_MAX);
}
