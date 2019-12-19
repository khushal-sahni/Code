//Goal is to randomly open sites in a n by n grid and see at what percentage does the grid percolate

#include <iostream>
#include <stdlib.h> //for rand
using namespace std;

// Quickunify class to facilitate percolation

class Quickunify
{
   int *id; //id of component i connected to
   int *sz; //size of subtree rooted at i
   public: int *open; //to check if site is open
   int num;// size of grid

  public: Quickunify(int n){
    id = new int [n*n + 2]; sz = new int [n*n + 2]; num = n; // a grid of n*n + 2 for source and sink
    for(int i = 0; i < n*n + 2; i++) {
      id[i] = i;
      sz[i] = 1;
      open[i] = 0;
    }
    open[n*n] = 1;
    open[n*n + 1] = 1;

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

  public: void openSite(int i){ //open site i
    open[i] = 1;
    if(i+num < num*num){
      if(open[i+num]) unify(i,i+num);
    }
    if(i-num > -1){
      if(open[i-num]) unify(i,i-num);
    }
    if(((i-1) % num) != 0){
      if(open[i-1]) unify(i,i-1);
     }
    if(((i+1) % num) != (num -1)){
      if(open[i+1]) unify(i,i+1);
    }

  }

};

int main(){
  int n = 10;
  Quickunify q(n); //a grid of n by n
  //Connect top and bottom of grid to virtual source and sink
  for(int i = 0; i < n ; i++){
    q.unify(i,n*n);// source vertex n*n unified with top line of grid
  }
  for(int i = n*n-1; i > n*n-(n+1); i--){
    q.unify(i,n*n+1);// sink vertex n*n + 1 unified with bottom of grid
  }

  cout << "Initialization done !";

  int count = 0; //count of number of sites opened
  float probability = n*n;
  while(!q.connected(n*n,(n*n)+1)){
    int site = rand()%(n*n);
    if(q.open[site]) continue;
    cout << "\n Opening Site: " << site;
    q.openSite(site); //open a random site
    count++;
  }
  probability = count/probability;
  cout << "\n" << "The probability of site opening for percolation: " << probability;

}
