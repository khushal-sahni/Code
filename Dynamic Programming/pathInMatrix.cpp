#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int hPath(int i, int j, void *ptr, int n, void *ptr1){
  int (*highestPath)[n] = static_cast <int (*)[n]>(ptr);
  if(highestPath[i][j] != -1) return highestPath[i][j];
  int (*matrix)[n] = static_cast <int (*)[n]>(ptr1);
  int val = 0;
  if(i < n-1){
    if(j < n-1) val = max(val, hPath(i+1,j+1,highestPath,n,matrix));
    if(j > 0) val = max(val, hPath(i+1,j-1,highestPath,n,matrix));
    val = max(val, hPath(i+1,j,highestPath,n,matrix));
  }
  return highestPath[i][j] = matrix[i][j] + val;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i,j, val = 0;
    cin >> n;
    int matrix[n][n];
    for(i = 0; i < n; i++) for(j = 0; j < n; j++) cin >> matrix[i][j];
    int highestPath[n][n];
    memset(highestPath,-1,sizeof(highestPath));
    for(i = 0; i < n; i++) val = max(val, hPath(0,i,highestPath,n,matrix));
    cout << val << "\n";
  }
}
