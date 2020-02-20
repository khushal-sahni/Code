struct Node
{
	int data;
	Node* next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};
Node * mergeKLists(Node *arr[], int N)
{
  bool found = false;
  int j;
  for(int i = 0; i < N; i++){
    if(!found && arr[i] != NULL){
      found = true;
      j = i;
      continue;
    }
    if(arr[i] != NULL && arr[i]->data < arr[j]->data) j = i;
  }
  if(!found) return NULL;
  Node* node = arr[j];
  arr[j] = arr[j]->next;
  node->next = mergeKLists(arr,N);
  return node;
}
