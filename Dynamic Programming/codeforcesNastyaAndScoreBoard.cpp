#include<bits/stdc++.h>
using namespace std;
using li = long int;
using lli  = long long int;

#define eb emplace_back
#define mt make_tuple
#define mp make_pair

int dp[2005][2005];
bitset <7> arr[2005];
vector <string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
vector <bitset <7>> bdigits;
int n,k;
string answer;

int canDo(bitset <7> a, bitset <7> b){//check if it is possible to convert a into b
  auto temp = a | b;
  if(temp.count() > b.count()) return -1;
  return b.count()-a.count();
}

int possible(int i, int k){
  if(dp[i][k] != -1) return dp[i][k];
  //write base cases
  if(i == n+1 ) return (k == 0);
  // if(k == 0) return 0;
  int ans = 0;
  for(int j = 9; j >= 0; --j){
    int x = canDo(arr[i],bdigits[j]);
    if(x != -1 && x <= k){
      ans = possible(i+1,k-x);
    }
    if(ans > 0) break;
  }
  return dp[i][k] = ans;
}

void genResult(int i, int k){
  //base cases
  if(i == n+1) return;
  for(int j = 9; j >= 0; --j){
    int x = canDo(arr[i],bdigits[j]);
    if(x != -1 && x <= k){
      if(possible(i+1,k-x)){
        char c = j + '0';
        answer += c;
        genResult(i+1,k-x);
        break;
      }
    }
  }

}

int main(){
  ios_base::sync_with_stdio(false);

  bdigits.clear();
  for(auto &x: digits){
    bdigits.eb(bitset <7> (x));
  }

    int i;
    string s;
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    for(i = 1; i <= n; ++i){
      cin >> s;
      arr[i] = bitset <7> (s);
    }
    if(possible(1,k)){
      answer = "";
      genResult(1,k);
      cout << answer << "\n";
    }
    else{
      cout << "-1\n";
    }


}
