#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool comp(int a, int b){
  return a>b;
}

void pushToLeft(vector <int> &leftHeap, int num){
  leftHeap.push_back(num);
  push_heap(leftHeap.begin(),leftHeap.end());
}

void pushToRight(vector <int> &rightHeap, int num){
  rightHeap.push_back(num);
  push_heap(rightHeap.begin(),rightHeap.end(),comp);
}

int main(){
  int n,d,val;
  cin >> n;
  vector <int> leftHeap;
  vector <int> rightHeap;
  make_heap(leftHeap.begin(),leftHeap.end());
  make_heap(rightHeap.begin(),rightHeap.end(),comp);

  while(n--){
    cin >> d;

    if(leftHeap.empty()) pushToLeft(leftHeap,d);
    else{
      val = leftHeap.front();
      if(d > val) pushToRight(rightHeap,d);
      else pushToLeft(leftHeap,d);
    }

    while(rightHeap.size() < leftHeap.size()-1){
      pop_heap(leftHeap.begin(),leftHeap.end());
      rightHeap.push_back(leftHeap.back());
      leftHeap.pop_back();
      push_heap(rightHeap.begin(),rightHeap.end(),comp);
    }
    while(rightHeap.size() > leftHeap.size()){
      pop_heap(rightHeap.begin(),rightHeap.end(),comp);
      leftHeap.push_back(rightHeap.back());
      rightHeap.pop_back();
      push_heap(leftHeap.begin(),leftHeap.end());
    }

    if(leftHeap.size() == rightHeap.size()){
      cout << floor( leftHeap.front() + (rightHeap.front()-leftHeap.front())/2 ) << "\n";
    }
    else{
      cout << leftHeap.front() << "\n";
    }
  }
}
