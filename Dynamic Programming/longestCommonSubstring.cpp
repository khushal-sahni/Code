#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int commonLength(int i, int j, string s1, string s2, vector <vector <int>> commonStringLength, int n, int m){
  if(commonStringLength[i][j] != -1) return commonStringLength[i][j];
  if(s1[i] == s2[j]){
    if(i == n-1 || j == m-1) return commonStringLength[i][j] = 1;
    return commonStringLength[i][j] = 1 + commonLength(i+1,j+1,s1,s2,commonStringLength,n,m);
  }
  else return commonStringLength[i][j] = 0;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,m, maximumLength = 0;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    vector <vector <int>> commonStringLength(n, vector <int> (m, -1));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(s1[i] == s2[j])  maximumLength = max(maximumLength,commonLength(i,j,s1,s2,commonStringLength,n,m));
      }
    }
    cout << maximumLength << "\n";
  }
}
