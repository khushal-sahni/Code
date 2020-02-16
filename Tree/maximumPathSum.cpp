struct Node{
	int data;
	Node *left, *right;
};

#include <climits>
int maxSum;

int func(Node *root){
  if(root == NULL) return 0;
  int leftSum = func(root->left);
  int rightSum = func(root->right);
  int sum = root->data;
  if(leftSum > 0) sum += leftSum;
  if(rightSum > 0) sum += rightSum;
  if(sum > maxSum) maxSum = sum;
  if(leftSum > 0 && leftSum > rightSum) return root->data+leftSum;
  if(rightSum > 0 && rightSum > leftSum) return root->data+rightSum;
  return root->data;
}

int maxPathSum(struct Node *root)
{
  maxSum = INT_MIN;
  func(root);
  return maxSum;
}
