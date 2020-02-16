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
#include <cstdlib>
#include <algorithm>
int func(Node* root){
  if(root == NULL) return 0;
  int leftHeight = func(root->left);
  int rightHeight = func(root->right);
  if(leftHeight == -1 || rightHeight == -1) return -1;
  if(abs(leftHeight-rightHeight) > 1) return -1;
  else return 1 + max(leftHeight,rightHeight);
}

bool isBalanced(Node *root)
{
  if(func(root) != -1) return true;
  else return false;
}
