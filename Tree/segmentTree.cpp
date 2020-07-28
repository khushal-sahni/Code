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

int sz;

lli build(int s, vl &v){

	if(2*s + 1 >= sz*2 - 1) return v[s];//leaf node
	v[s] = build(2*s+1,v) + build(2*s + 2,v);

	return v[s];
}

void update(int s, vl &v){
	v[s] = v[2*s+1] + v[2*s+2];
	if(s == 0) return ;
	int parent = (s-1)/2;
	update(parent,v);
};

lli sum(int l, int r, vl &v, int ll, int rr, int key){

	if(max(l,ll) > min(r,rr)) return 0;//no intersection
	if(l <= ll && r >= rr){//l r range completely covers ll - rr range
		
		return v[key];
	} 
	int mid = ll + (rr-ll)/2;

	return sum(l,r,v,ll,mid,2*key+1) + sum(l,r,v,mid+1,rr,2*key+2);
}

int main(){
  ios_base::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  sz = 1;
  while(sz < n) sz *= 2;

  vl v(sz*2 - 1,0);
  for(int i = 0; i < n; ++i) cin >> v[sz-1+i];

  build(0,v);
 
  while(m--){
	  int q;
	  cin >> q;
	  if(q == 1){
		  int i;
		  lli val;
		  cin >> i >> val;
		  int pos = sz-1 + i;
		  v[pos] = val;
		  if(pos > 0)update((pos-1)/2,v);
	  }
	  else{
		  int l, r;
		  cin >> l >> r;
		  cout << sum(l,r-1,v,0,sz-1,0) << "\n";
	  }
  }
}
