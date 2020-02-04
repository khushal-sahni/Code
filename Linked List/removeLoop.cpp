#include <iostream>
void removeTheLoop(Node *head){
  Node *hare = head, *turtle = head, *prev, *point;
  while(hare->next != NULL && hare->next->next != NULL){
    hare = hare->next->next;
    turtle = turtle->next;
    if(turtle == hare){
      point = hare;
      break;
    }
  }
  prev = head;
  while(point->next != NULL){
    if(point->next == prev->next){
      point->next = NULL;
      break;
    }
    point = point->next;
    prev = prev->next;
  }
}
