#include <iostream>
#include <map>
#include <queue>
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
void bottomView(Node* root){
  map <int, int> x;
  queue <pair <Node *, int> > q;
  int hd; Node* node;
  q.push(pair<Node* ,int>(root, 0));
  while(!q.empty()){
    node = q.front().first;
    hd = q.front().second;
    q.pop();
    if(x.find(hd) == x.end()) x.insert(pair <int, int> (hd, node->data));
    else x[hd] = node->data;
    if(node->left != NULL) q.push(pair<Node*, int>(node->left, hd-1));
    if(node->right != NULL) q.push(pair<Node*, int>(node->right, hd+1));
  }
  for(auto i = x.begin(); i != x.end(); i++) cout << (i->second) << " ";
}
