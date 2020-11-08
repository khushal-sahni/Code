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

vi o,c;

void csort(){
	int n = o.size();
	vi o1(n),cnt(n),pos(n);
	for(auto &x: c) ++cnt[x];
	pos[0] = 0;
	for(int i = 1; i < n; ++i) pos[i] = pos[i-1] + cnt[i-1];
	for(auto &x: o){
		o1[pos[c[x]]] = x;
		++pos[c[x]];
	}
	o = o1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  s += "!";
  int n = s.size();
  o.resize(n);
  c.resize(n);
  {
	  vector <pair <char,int>> temp;
	  for(int i = 0; i < n; ++i)temp.eb(s[i],i);
	  sort(temp.begin(),temp.end());
	  for(int i = 0; i < n; ++i) o[i] = temp[i].ss;
	  c[o[0]] = 0;
	  for(int i = 1; i < n; ++i){
		  if(temp[i].ff == temp[i-1].ff) c[o[i]] = c[o[i-1]];
		  else c[o[i]] = c[o[i-1]] + 1;
	  }
  }
  int k = 0; 
  while((1 << k) < n){
	  for(int i = 0; i < n; ++i) o[i] = (o[i] - (1 << k) + n)%n;
	  csort();
	  vi c1(n);
	  c1[o[0]] = 0;
	  for(int i = 1; i < n; ++i){
		  pi curr = {c[o[i]], c[(o[i] + (1 << k))%n]};
		  pi prev = {c[o[i-1]], c[(o[i-1] + (1 << k))%n]};
		  if(curr == prev) c1[o[i]] = c1[o[i-1]];
		  else c1[o[i]] = c1[o[i-1]] + 1;
	  }
	  c = c1;
	  ++k;
  }
  pl(o);
  int common = 0;
  vi lcp(n);
  for(int i = 0; i < n-1; ++i){
	  int top = o[c[i]-1] + common, bot = i + common;
	  while(top < n && bot < n && s[top] == s[bot]){
		  ++top;
		  ++bot;
		  ++common;
	  }
	  lcp[c[i]] = common;
	  common = max(common-1,0);
  }
  for(int i = 1; i < n; ++i) cout << lcp[i] << " ";
  
}
