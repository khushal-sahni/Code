struct Node{
  int data;
  struct Node* next;
  Node(int x){
    data = x;
    next = NULL;
  }
};
bool isPalindrome(Node *head){
  int length = 0, i = 1;
  Node* node = head, *first, *second, *third, *nodee;
  while(node != NULL) {
    length++;
    node = node->next;
  }
  if (length <= 1) return true;
  first = head; second = first->next;
  while(i < length/2 && second->next != NULL){
    third = second->next;
    second->next = first;
    first = second;
    second = third;
    i++;
  }
  node = first;
  if((length % 2) == 1) nodee = second->next;
  else nodee = second;
  while(node != NULL && nodee!= NULL){
    if(node->data != nodee->data) return false;
    node = node->next;
    nodee = nodee->next;
  }
  return true;
}
