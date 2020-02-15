#include <iostream>
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
Node* LCA(Node *root, int n1, int n2)
{
   Node* lca = root;
   Node* node = root;
   while(node != NULL){
     if(node->data < n1){
       if(node->data > n2) return lca;
       if(node->data == n2) return node;
       node = node->right;
       lca = node;
     }
     else if(node->data > n1){
       if(node->data < n2) return lca;
       if(node->data == n2) return node;
       node = node->left;
       lca = node;
     }
     else return node;
   }
}
