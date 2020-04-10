#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


int mLength(int i, int j, int a, int b, string s1, string s2, void *ptr){
  int (*length)[b] = static_cast <int (*)[b]>(ptr);
  int maxLength = 0;
  if(length[i][j] != -1) return length[i][j];
  if(s1[i] == s2[j]){
    if(i == a-1 || j == b-1) return length[i][j] = 1;
    for(int p = i+1; p < a; p++){
      for(int q = j+1; q < b; q++){
        if(s1[p] == s2[q]) maxLength = max(maxLength, mLength(p,q,a,b,s1,s2,length));
      }
    }
    return length[i][j] = 1 + maxLength;
  }
  else return length[i][j] = 0;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int a, b, maxLength = 0, p = -1, q = -1;
    string s1,s2;
    cin >> s1 >> s2;
    a = s1.length();
    b = s2.length();
    int length[a][b];
    memset(length,-1,sizeof(length));
    for(int i = 0; i < a; i++){
      for(int j = 0; j < b; j++){
        if(s1[i] == s2[j]) maxLength = max(maxLength, mLength(i,j,a,b,s1,s2,length));
      }
    }

    cout << a + b - maxLength << "\n";
  }
}

// another faster solution

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    string s1,s2; cin>>s1>>s2;
	    int n=s1.length();
	    int m=s2.length();
	    int dp[n+1][m+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=m;j++){
	            if(i==0 || j==0) dp[i][j]=0;
	            else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
	            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    cout<<n+m-dp[n][m]<<endl;
	}
	return 0;
}
