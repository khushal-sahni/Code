#include <iostream>
#include <algorithm>
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
int height(Node* node)
{  if(node == NULL) return 0;
   return 1+max(height(node->left),height(node->right));
}
