#include <iostream>
#include <unordered_set>
using namespace std;
class Node{
public:
  int data;
  Node *next;
};

void printList(Node *head){
  auto node = head;
  while(node != NULL){
    cout << node->data << "\n";
    node = node->next;
  }
  cout << "\n";
}

int intersectPoint(Node *head1, Node* head2){
  //one way of doing it is using unordered_set
  unordered_set<Node*>set;
  while(head1->next != NULL)
  {
      set.insert(head1);
      head1 = head1->next;
  }

  int flag = 0;
  while(head2->next != NULL)
  {
      if(set.find(head2) != set.end())
      {
          flag = 1;
          return head2->data;
      }
      head2 = head2->next;
  }
  return -1;
  //another way is to simply determine where they intersect by measuring lists length
    int l=0;
    int l1=0;
     Node*p=head1;
     Node*q=head2;

     while(p->next!=NULL)
     {
         l++;
         p=p->next;
     }
     while(q->next!=NULL)
     {
         l1++;
         q=q->next;
     }
     int d=abs(l1-l);
     Node*m=head1;
     Node*n=head2;
     if(l>l1)
     {
         for(int i=0; i<d; i++)
           m=m->next;

     }
      else
      {

          for(int i=0; i<d; i++)
              n=n->next;
      }
      while(m!=NULL && n!=NULL)
      {
          if(m==n)
          {
              return m->data;
          }
          m=m->next;
          n=n->next;
      }
      return -1;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,m,data;
    scanf("%d %d",&n,&m);

    scanf("%d",&data);
    Node *head = new Node();
    head->data = data;
    head->next = NULL;
    Node *prev = head;

    for(int i = 1; i < n; i++){
      Node *newNode = new Node();
      scanf("%d",&data);
      newNode->data = data;
      newNode->next = NULL;
      prev->next = newNode;
      prev = newNode;
    }

    scanf("%d",&data);
    Node *head2 = new Node();
    head2->data = data;
    head2->next = NULL;
    prev = head2;

    for(int i = 1; i < m; i++){
      Node *newNode = new Node();
      scanf("%d",&data);
      newNode->data = data;
      newNode->next = NULL;
      prev->next = newNode;
      prev = newNode;
    }

    cout << "Printing first list\n";
    printList(head);
    cout << "\n Printing second list\n" ;
    printList(head2);
    cout << "\n common element " << intersectPoint(head,head2);

  }
}
