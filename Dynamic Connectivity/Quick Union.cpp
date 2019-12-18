#include <iostream>
using namespace std;
class Quickunify
{
   int *id; //id of component i connected to
   int *sz; //size of subtree rooted at i

  public: Quickunify(int n){
    id = new int [n]; sz = new int [n];
    for(int i = 0; i < n; i++) {
      id[i] = i;
      sz[i] = 1;
    }

  }

   int root(int i){
    while(i != id[i]){
      id[i] = id[id[i]]; //Path Compression
      i = id[i];
    }
    return i;
  }

  public: bool connected(int p, int q){
    return root(p) == root(q);
  }

 public: void unify(int p, int q){
    int i = root(p);
    int j = root(q);
    if(sz[i] > sz[j]){
      id[j] = i;
      sz[i] += sz[j];
    } // Adding smaller tree to the larger one
    else{
      id[i] = j;
      sz[j] += sz[i];
    }
  }

};

int main(){
  Quickunify q(5);
  q.unify(0,1);
  q.unify(4,3);
  q.unify(3,0);
  cout << q.connected(1,4);
}
