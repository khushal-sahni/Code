#include <iostream>
#include <string>
#include <cstring>
#include <climits>
using namespace std;

int dp[41][41];
int find(int start,int end,string &s){
    int ans = INT_MAX;
    if(start == end) return 0;
    if(start+1 == end) return (!(s[start]==s[end]));
    if(dp[start][end] != -1)return dp[start][end];
    if(s[start] == s[end]) ans = min(ans,find(start+1,end-1,s));
    ans =  min(ans,find(start+1,end,s)+1);
    ans =  min(ans,find(start,end-1,s)+1);
    return dp[start][end] = ans;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    memset(dp,-1,sizeof(dp));
	    int ans = find(0,s.size()-1,s);
	    cout<<ans<<endl;
	}
	return 0;
}
