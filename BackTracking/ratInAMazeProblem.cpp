#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool visited[5][5];
int mat[5][5];

void func(int r, int c, int n, string s, vector <string> &v){


  if(mat[r][c] == 0) return;
  if(r == n-1 && c == n-1){
    v.push_back(s);
    return;
  }
  if(r < n-1 && !visited[r+1][c]){
    visited[r+1][c] = true;
    func(r+1,c,n, s+'D',v);
    visited[r+1][c] = false;
  }
  if(c > 0 && !visited[r][c-1]){
    visited[r][c-1] = true;
    func(r,c-1,n, s+'L',v);
    visited[r][c-1] = false;
  }
  if(c < n-1 && !visited[r][c+1]){
    visited[r][c+1] = true;
    func(r,c+1,n, s+'R',v);
    visited[r][c+1] = false;
  }
  if(r > 0 && !visited[r-1][c]){
    visited[r-1][c] = true;
    func(r-1,c,n, s+'U',v);
    visited[r-1][c] = false;
  }
}

vector<string> printPath(int m[MAX][MAX], int n)
{
	vector <string> v;
  memset(visited,0,sizeof(visited));
  visited[0][0] = true;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) mat[i][j] = m[i][j]; //value copying
  func(0,0,n,"",v);
  return v;
}
