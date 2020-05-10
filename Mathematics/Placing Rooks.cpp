#include<bits/stdc++.h>
using namespace std;
using li = long int;
using lli  = long long int;

#define eb emplace_back
#define mt make_tuple
#define mp make_pair
#define mod 998244353

int fact[200001];

int power(int n, int p);

int inv(int x){
  return power(x,mod-2);
}

int combo(int n, int c){
  lli res = fact[n];
  res *= inv((fact[n-c] * 1ll * fact[c])%mod);
  return res%mod;
};

int power(int n, int p){
  int z = 1;
  while(p > 0){
    if(p%2 == 1){
      z = (z * 1ll * n) % mod;
    }
    n = (n * 1ll * n) % mod;
    p /= 2;
  }
  return z;
}

int add(int x, int y){
  return (x + y)%mod;
}

int sub(int x, int y){
  return add(x,mod-y);

}

int main(){
  ios_base::sync_with_stdio(false);
  int n,k,c, ans,i,d = -1, x;
  cin >> n >> k;
  c = n - k;
  if(c <= 0) cout << 0 << "\n";
  else{
    ans = power(c,n);
    // cout << "answer here " << ans << "\n";
    //factorial making
    fact[0] = 1;
    for(i = 1; i <= n; i++) fact[i] = (fact[i-1] * 1ll * i) % mod;
    for(i = 1; i <= c; i++){
      if(d == -1){
        ans = sub(ans,(power(c-i,n)*1ll*combo(c,i))%mod);
      }
      else{
        ans = add(ans,(power(c-i,n)*1ll*combo(c,i))%mod);
      }
      // cout << "answerr here " << ans << "\n";
      d = -d;
    }
    ans = (ans * 1ll * combo(n,c))%mod;
    // cout << "answer here " << ans << "\n";
    if(k == 0) cout << ans << "\n";
    else{
      ans = (ans * 1ll * 2)%mod;
      // cout << "answer here " << ans << "\n";
      cout << ans << "\n";
    }
  }
}
