#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
   Node(int x) {
       data = x;
       next = NULL;
   }
};

Node *segregate(Node* head){
 Node *node = head;
 int count0 = 0, count1 = 0, count2 = 0;
 while(node != NULL){
   if(node->data == 0) count0++;
   else if(node->data == 1) count1++;
   else count2++;
   node = node->next;
 }
 node = head;
 while(count0--){
   node->data = 0;
   node = node->next;
 }
 while(count1--){
   node->data = 1;
   node = node->next;
 }
 while(count2--){
   node->data = 2;
   node = node->next;
 }
 return head;
}
