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

vi lps;

void func(string &s){
	lps.resize(s.size());
	lps[0] = 0;
	int len = 0, i = 1;
	while(i < n){
		if(s[i] == s[len]){
			++len;
			lps[i] = len;
			++i;
		}
		else{
			if(len > 0){
				len = lps[len-1];
			}
			else{
				lps[i] = 0;
				++i;
			}
		}
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  func(s);
}
