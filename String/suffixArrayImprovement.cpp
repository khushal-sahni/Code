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
#define vi vector <int>
#define vc vector <char>
#define vl vector <lli>
#define p(x) cout << #x << " is " << (x) << " on Line:" << __LINE__ << " \n";
#define pl(x) for(auto &y:x) cout << y << " "; cout << "\n";

void rsort(vector <pair <pair <int,int>,int>> &v){
	int n = v.size();
	vector <int> cnt(n);
	for(auto &x: v) ++cnt[x.ff.ss];
	vector <pair <pair <int,int>,int>> v1(n);
	vi pos(n);
	pos[0] = 0;
	for(int i = 1; i < n; ++i) pos[i] = pos[i-1] + cnt[i-1];
	for(auto &x:v){
		v1[pos[x.ff.ss]] = x;
		++pos[x.ff.ss];
	}
	//doing for the first element now
	fill(cnt.begin(),cnt.end(),0);
	for(auto &x: v1) ++cnt[x.ff.ff];
	pos[0] = 0;
	for(int i = 1; i < n; ++i) pos[i] = pos[i-1] + cnt[i-1];
	for(auto &x:v1){
		v[pos[x.ff.ff]] = x;
		++pos[x.ff.ff];
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  s += '!';
  int n = s.length();
  vi o(n),c(n);
  {
	  //k = 0
	  vector <pair <char,int> >a(n);
	  for(int i = 0; i < n; ++i){
		  a[i] = {s[i],i};
	  }
	  sort(a.begin(),a.end());
	  for(int i =0; i < n; ++i) o[i] = a[i].ss;
	  c[o[0]] = 0;
	  for(int i = 1; i < n; ++i){
		  if(a[i].ff == a[i-1].ff) c[o[i]] = c[o[i-1]];//a[i].ss can also be used instead of o[i]
		  else c[o[i]] = c[o[i-1]] + 1;
	  }
  }
  int k = 0;
  // as you can see the index every time from 0 to n-1 refers to the substring which starts at
  // the index
  while((1 << k) < n){
	  //k to k+1 transition
	  vector <pair <pair <int,int>,int>> a(n);
	  for(int i = 0; i < n; ++i){
		  a[i] = {{c[i],c[(i+ (1 << k) )%n]},i};
	  }
	  rsort(a);
	  for(int i = 0; i < n; ++i) o[i] = a[i].ss;
	  c[o[0]] = 0;
	  for(int i = 1; i < n; ++i){
		  if(a[i].ff == a[i-1].ff) c[o[i]] = c[o[i-1]];
		  else c[o[i]] = c[o[i-1]] + 1;
	  }
	  if(c[o[n-1]] == n-1) break;//sufficient classes
	  ++k;
  }
  pl(o);
}
