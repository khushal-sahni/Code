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
#include <climits>
int maxDiameter;

int func(Node* node){
  if(node == NULL) return 0;
  int leftLength = func(node->left);
  int rightLength = func(node->right);
  int length = 1+leftLength+rightLength;
  if(length > maxDiameter) maxDiameter = length;
  if(leftLength > rightLength) return 1+leftLength;
  else return 1+rightLength;
}

int diameter(Node* node)
{
   maxDiameter = INT_MIN;
   func(node);
   return maxDiameter;
}
