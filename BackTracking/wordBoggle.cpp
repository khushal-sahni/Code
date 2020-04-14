#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

char boggle[7][7];

set <string> answers;
bool visited[7][7];
string searchedString;

bool func(int r, int c, int n, int m, int index){

  if(boggle[r][c] != searchedString[index]) return false;
  index++;
  if(index == searchedString.length()) return true;
  if(r < n-1 && !visited[r+1][c]){ //bottom
    visited[r+1][c] = true;
    if(func(r+1,c,n,m,index)) return true;
    visited[r+1][c] = false;
  }
  if(r < n-1 && c < m-1 && !visited[r+1][c+1]){
    visited[r+1][c+1] = true;
    if(func(r+1,c+1,n,m,index)) return true;
    visited[r+1][c+1] = false;
  }
  if(r < n-1 && c > 0 && !visited[r+1][c-1]){
    visited[r+1][c-1] = true;
    if(func(r+1,c-1,n,m,index)) return true;
    visited[r+1][c-1] = false;
  }
  if(r > 0 && !visited[r-1][c]){
    visited[r-1][c] = true;
    if(func(r-1,c,n,m,index)) return true;
    visited[r-1][c] = false;
  }
  if(r > 0 && c < m-1 && !visited[r-1][c+1]){
    visited[r-1][c+1] = true;
    if(func(r-1,c+1,n,m,index)) return true;
    visited[r-1][c+1] = false;
  }
  if(r > 0 && c > 0 && !visited[r-1][c-1]){
    visited[r-1][c-1] = true;
    if(func(r-1,c-1,n,m,index)) return true;
    visited[r-1][c-1] = false;
  }
  if(c < m-1 && !visited[r][c+1]){
    visited[r][c+1] = true;
    if(func(r,c+1,n,m,index)) return true;
    visited[r][c+1] = false;
  }
  if(c > 0 && !visited[r][c-1]){
    visited[r][c-1] = true;
    if(func(r,c-1,n,m,index)) return true;
    visited[r][c-1] = false;
  }
  return false;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int x,i,j,n,m;
    bool found = false;
    cin >> x;
    vector <string> v(x);

    answers.clear();
    for(i = 0; i < x; i++){
      cin >> v[i];
    }
    cin >> n >> m;

    for(i = 0; i < n; i++) for(j = 0; j < m; j++) cin >> boggle[i][j];

    for(int k = 0; k < x; k++){
      searchedString = v[k];
      found = false;
      for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
          if(boggle[i][j] == searchedString[0]){
            memset(visited,0,sizeof(visited));
            visited[i][j] = true;
            if(func(i,j,n,m,0)){
              answers.insert(searchedString);
              found = true;
              break;
            }
          }
        }
        if(found) break;
      }
    }

    if(answers.empty()) cout << "-1\n";
    else{
      for(auto k = answers.begin(); k != answers.end(); k++) cout << (*k) << " ";
      cout << "\n";
    }



  }
}
