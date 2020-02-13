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
int maxLevel = -1;
void lefttView(Node* root, int level){
  if(root == NULL) return;
  if(level > maxLevel){
    cout << root->data << " ";
    maxLevel = level;
  }
  if(root->left) lefttView(root->left, level+1);
  if(root->right) lefttView(root->right, level+1);
}

void leftView(Node* root){
  maxLevel = -1;
  lefttView(root, 0);
}
