struct Node
{
    int data;
    Node* left;
    Node* right;
};
#include <queue>

Node* createNode(){
  Node* node = new Node(NULL);
  node->left = NULL;
  node->right = NULL;
  return node;
}

void serialize(Node *root,vector<int> &A)
{
    if(root == NULL) return;
    queue <Node *> q;
    Node *node;

    q.push(root);
    while(!q.empty()){
      node = q.front();
        A.push_back(node->data);
        if(node->data != NULL){
          if(node->left != NULL) q.push(node->left);
          else q.push(createNode());
          if(node->right != NULL) q.push(node->right);
          else q.push(createNode());
        }
      q.pop();
    }

}
Node * deSerialize(vector<int> &A)
{
   if(A.empty()) return NULL;
   Node* root = new Node(A[0]);
   queue <Node *> q;
   Node *node;
   q.push(root);
   for(int i = 1; i < A.size();){
     node = q.front();
     if(A[i] != NULL){
       node->left = new Node(A[i]);
       q.push(node->left);
     }
     else node->left = NULL;
     i++;
     if(A[i] != NULL){
       node->right = new Node(A[i]);
       q.push(node->right);
     }
     else node->right = NULL;
     i++;
     q.pop();
   }
   return root;
}
