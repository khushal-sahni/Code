#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define vi vector <int>
#define pi pair <int, int>
#define ff first
#define ss second
#define eb emplace_back

vi o,c;

void csort(){
  int n = o.size();
  vi o1(n), pos(n), cnt(n);
  for(auto &val: c) ++cnt[val];
  pos[0] = 0;
  rep(i,1,n) pos[i] = pos[i-1] + cnt[i-1];
  for(auto &val: o){
    o1[pos[c[val]]] = val;
    ++pos[c[val]];
  }
  o = o1;
}

int main(){
  string s;
  cin >> s;
  s += "!";
  int n = s.size();
  o.resize(n);
  c.resize(n);
  {
    vector <pi> vec;
    rep(i,0,n) vec.eb(s[i],i);
    sort(vec.begin(), vec.end());
    rep(i,0,n) o[i] = vec[i].ss;
    c[o[0]] = 0;
    rep(i,1,n){
      if(vec[i].ff == vec[i-1].ff) c[o[i]] = c[o[i-1]];
      else c[o[i]] = c[o[i-1]] + 1;
    }
  }
  int k = 0;
  while( (1 << k) < n){
    rep(i,0,n) o[i] = (o[i] - (1 << k) + n) % n;
    csort();
    vi c1(n);
    c1[o[0]] = 0;
    rep(i,1,n){
      pi curr = {c[o[i]], c[ (o[i] + (1 << k)) % n ]};
      pi prev = {c[o[i-1]], c[ (o[i-1] + (1 << k)) % n ]};
      if(curr == prev) c1[o[i]] = c1[o[i-1]];
      else c1[o[i]] = c1[o[i-1]] + 1;
    }
    ++k;
    c = c1;
  }

  int common = 0;
  vi lcp(n);
  rep(i,0,n-1){
    int top = o[c[i] - 1] + common, bot = i + common;
    while(top < n && bot < n && s[top] == s[bot]){
      ++top;
      ++bot;
      ++common;
    }
    lcp[c[i]] = common;
    common = max(common-1, 0);
  }

  for(auto &val: o) cout << val << " "; cout << "\n";
  for(auto &val: lcp) cout << val << " "; cout << "\n";

}
