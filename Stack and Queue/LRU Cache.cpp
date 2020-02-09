#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int key;
    int value;
    Node *next,*pre;
    Node(int key, int value)
    {
        this->key=key;
        this->value=value;
        next=pre=NULL;
    }

};
class LRUCache
{
    private:

    static unordered_map<int,Node *> hsmap;
    static int capacity,count;
    static Node *head,*tail;

    public:

    LRUCache(int cap)
    {
        capacity = cap;
        count = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        head->pre = NULL;
        tail->next = NULL;
        tail->pre = head;
        hsmap.clear();
    }

    static void deleteNode(Node* node){
      node->pre->next = node->next;
      node->next->pre = node->pre;
    }

    static void addToHead(Node* node){
      node->next = head->next;
      node->next->pre = node;
      head->next = node;
      node->pre = head;
    }

    static int get(int key)
    {
        if(hsmap.find(key) != hsmap.end()){
          struct Node* node = hsmap.find(key)->second;
          deleteNode(node);
          addToHead(node);
          return node->value;
        }
        else return -1;
    }

    static void set(int key, int value)
    {
        if(hsmap.find(key) != hsmap.end()){
          struct Node *node = hsmap.find(key)->second;
          node->value = value;
          deleteNode(node);
          addToHead(node);
        }
        else{
          if(count == capacity){
            hsmap.erase(tail->pre->key);
            deleteNode(tail->pre);
            count--;
          }
          struct Node *node = new Node(key, value);
          addToHead(node);
          hsmap.insert(pair <int,Node *> (key, node));
          count++;
        }
    }

};

// https://practice.geeksforgeeks.org/problems/lru-cache/1
