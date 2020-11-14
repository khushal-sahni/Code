//Question Description given range of numbers find which sum (sum of digits of numbers in that range)
// appears the maximum times, let's say 1,2,...10 here 2,3,...9 appears once and 1 appears twice
// let's say the maximum time appearing sum appears counter times, find the count of all sum who appear
// counter times and output them along with the counter value

#include<bits/stdc++.h>
using namespace std;
using li = long int;
using lli  = long long int;

#define eb emplace_back
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pi pair <int,int>
#define pll pair <lli,lli>
#define vi vector <int>
#define vl vector <lli>
#define p(x) cout << #x << " is " << (x) << " on Line:" << __LINE__ << " \n";
#define pl(x) for(auto &y:x) cout << y << " "; cout << "\n";
#define ppl(x) for(auto &y:x) cout << y.ff << " " << y.ss << " | ";cout << "\n";
#define um unordered_map

lli limit = 1e18;
int maxsum = 9*19 + 1;

lli number(vector <vl> &dp, lli maxn, lli sum){//
	vi digits;
	while(maxn){
		int d = maxn%10;
		maxn /= 10;
		digits.eb(d);
	}
	lli ans = 0;
	for(int i = digits.size()-1; i >= 0; --i){
		if(sum < 0) break;
		for(int j = 0; j < digits[i]; ++j){
			if(sum < j) continue;
			ans += dp[i][sum - j];
		}
		sum -= digits[i];
	}
	if(sum >= 0) ans += dp[0][sum];
	return ans;
}

void func(lli lowlimit, lli highlimit){
	vector <vl> dp(20, vl (maxsum));
	dp[0][0] = 1;
	for(int i = 1; i <= 19; ++i){
		for(int j = 0; j < maxsum; ++j){
			for(int k = 0; k <= 9; ++k){
				if(j < k) break;
				dp[i][j] += dp[i-1][j-k];
			}
		}
	}
	lli counter[maxsum];
	for(int i = 0; i < maxsum; ++i){
		counter[i] = number(dp,highlimit,i) - number(dp,lowlimit-1,i);
	}
	lli ans = 0;
	for(auto &x: counter) ans = max(ans, x);
	lli ways = 0;
	for(auto &x: counter) if(x == ans) ++ways;
	cout << ways << "\n" << ans << "\n";
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  lli lowl, highl;
  cin >> lowl >> highl;
  func(lowl,highl);
}

