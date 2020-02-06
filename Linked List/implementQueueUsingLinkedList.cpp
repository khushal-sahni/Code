#include <iostream>
using namespace std;
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

//  structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};

/* The method push to push element into the queue*/
void MyQueue:: push(int x)
{
        // Your Code
        struct QueueNode *newNode = new QueueNode(x);
        newNode->next = front;
        front = newNode;
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
        struct QueueNode *node = front;
        int value;
        if(node == NULL) return -1;
        if(node->next == NULL){
          value = node->data;
          node = NULL;
          front = NULL;
          return value;
        }
        while(node->next->next != NULL) node = node->next;
        value = node->next->data;
        node->next = NULL;
        rear = node;
        return value;
}
int main(){
  cout << "domo";
}
