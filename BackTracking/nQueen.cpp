#include <iostream>
#include <vector>
using namespace std;

vector <vector <bool>> visit(int r, int c, vector < vector <bool>> visited, int n){
  int i,j;

  for(j = c; j < n; j++) visited[r][j] = true;
  // for(i = 0; i < n; i++) visited[i][c] = true; not necessary only right, top right, bottom right
  i = r+1; j = c+1;
  while(i < n && j < n){
    visited[i][j] = true;
    i++; j++;
  }
  i = r-1; j = c+1;
  while(i >= 0 && j < n){
    visited[i][j] = true;
    i--; j++;
  }
  return visited;
}

bool func(int c, vector <vector <bool>> visited, vector <int> positions, int n){ //false case
  if(c == n){
    cout << "[";
    for(int i = 0; i < n; i++) cout << positions[i] << " ";
    cout << "] ";
    return true;
  }
  bool val = false;
  for(int i = 0; i < n; i++){ // all the rows
    if(!visited[i][c]){
      positions[c] = i + 1;
      if(func(c+1,visit(i,c,visited,n), positions,n)) val = true;
    }
  }
  return val;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector <int> positions(n,-1);
    vector < vector <bool>> visited (n,vector <bool> (n,0));
    if(!func(0,visited,positions,n)) cout << "-1";
    cout << "\n";
  }
}
