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

int siz;

void csort(vi &o, vi &c){
	int n = o.size();
	vi cnt(n,0);
	for(int i = 0; i < n; ++i)++cnt[c[i]];
	vi pos(n);
	pos[0] = 0;
	for(int i = 1; i < n; ++i) pos[i] = pos[i-1] + cnt[i-1];
	vi o1(n);
	for(auto &x: o){
		o1[pos[c[x]]] = x;
		++pos[c[x]];
	}
	o = o1;
}

int build(int key, vi &tree){
	if(key*2 +1 >= 2*siz-1) return tree[key];
	tree[key] = min(build(2*key+1,tree),build(2*key+2,tree));
	return tree[key];
}

int mini(int key, int l, int r, int ss, int se, vi &tree){
	if(max(l,ss) > min(r,se)) return INT_MAX;
	if(l <= ss && r >= se) return tree[key];
	int mid = ss + (se-ss)/2;
	return min(mini(key*2+1,l,r,ss,mid,tree),mini(key*2+2,l,r,mid+1,se,tree));
}

struct comp{
	vi &tree,&c;
	string &origs;
	comp(vi &v, vi &cl, string &str):tree(v),c(cl),origs(str){};
	bool operator()(pair <int,int> f, pair <int,int> s){
		--f.ff,--f.ss,--s.ff,--s.ss;
		int low = min(c[f.ff],c[s.ff]), up = max(c[f.ff],c[s.ff]);
		++low;
		auto len = mini(0,low,up,0,siz-1,tree);
		if(len == INT_MAX)goto here;
		f.ff += len;
		s.ff += len;
		if(f.ff > f.ss && s.ff <= s.ss) return true;//
		if(f.ff <= f.ss && s.ff > s.ss) return false;
		if(f.ff <= f.ss && s.ff <= s.ss){
			return origs[f.ff] < origs[s.ff];
		}
		if(f.ss-f.ff < s.ss-s.ff) return true;
		if(f.ss-f.ff > s.ss-s.ff) return false;
		here:return f < s;
	}
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >>s ;
  s += (char)(0);
  int n = s.length();
  int sz;
  cin >> sz;
  vector <pair <int,int>> val(sz);
  for(auto &x: val) cin >> x.ff >> x.ss;
  vi o(n),c(n);
  {
	  vector <pair<char,int>> a(n);
	  for(int i = 0; i < n; ++i){
		  a[i] = {s[i],i};
	  }
	  sort(a.begin(),a.end());
	  for(int i = 0; i < n; ++i)o[i] = a[i].ss;
	  c[o[0]] = 0;
	  for(int i = 1; i < n; ++i){
		  if(a[i].ff == a[i-1].ff) c[o[i]] = c[o[i-1]];
		  else c[o[i]] = c[o[i-1]] + 1;
	  }
  }
  int k = 0;
  while((1 << k) < n){
	  for(int i = 0; i < n; ++i)o[i] = (o[i]- (1 << k) + n)%n;
	  csort(o,c);
	  vi c1(n);
	  c1[o[0]] = 0;
	  for(int i = 1; i < n; ++i){
		  pair <int,int> prev = {c[o[i-1]],c[(o[i-1] + (1 << k))%n] };
		  pair <int,int> now = {c[o[i]],c[(o[i] + (1 << k))%n] };
		  if(prev == now) c1[o[i]] = c1[o[i-1]];
		  else c1[o[i]] = c1[o[i-1]] + 1;
	  }
	  c = c1;
	  if(c[n-1] == n-1) break;
	  ++k;
  }
  vi lcp(n);
  int common = 0;
  for(int i = 0; i < n-1; ++i){
	  int top = o[c[i]-1] + common, bot = i + common;
	  while(top < (int)s.length() && bot < (int)s.length() && s[top] == s[bot]){
		  ++common,++top,++bot;
	  }
	  lcp[c[i]] = common;
	  common = max(common-1,0);
  }
  siz = 1;
  while(siz < n) siz *= 2;
  vector <int> tree(2*siz - 1);
  for(int i = 0; i < n; ++i)tree[siz-1+ i] = lcp[i];
  build(0,tree);
  sort(val.begin(),val.end(),comp(tree,c,s));
  for(auto &x: val) cout << x.ff << " " << x.ss << "\n";
}
