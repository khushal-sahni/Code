#include<bits/stdc++.h>
using namespace std;
using li = long int;
using lli  = long long int;

#define eb emplace_back
#define mt make_tuple
#define mp make_pair

int fenwick[1000001];
int n;

void update(int i, int num){
  while(i <= n){
    fenwick[i] += num;
    i += i & -i;
  }
}

int sum(int i){
  int s = 0;
  while(i > 0){
    s += fenwick[i];
    i -= i & -i;
  }
  return s;
}

int findkth(int k, int l, int r){
  if(l <= r){
    int mid = l + (r-l)/2;
    if(sum(mid) >= k){
      auto x = findkth(k,l,mid-1);
      if(x != 0) return x;
      return mid;
    }
    else{
      return findkth(k,mid+1,r);
    }
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  int q,i,d;
  cin >> n >> q;
  memset(fenwick,0,sizeof(fenwick));
  for(i = 1; i <= n; ++i){
    cin >> d;
    update(d,1);
  }

  while(q--){
    cin >> d;
    if(d > 0){
      update(d,1);
    }
    else{
      d = -d;
      auto x = findkth(d,1,n);
      update(x,-1);
    }
  }
  cout << findkth(1,1,n) << "\n";

}
