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

int func(int n){
	int temp = n;
	int  p = 1;
	while(n % 2 == 0){
		p *= 2;
		n /= 2;
	}
	n /= 2;
	p *= 2;
	if(n % 2 == 0) return temp + p;
	else return temp - p;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, ans = INT_MAX;
  cin >> n;
  unordered_map <int,bool> mapp;
  mapp[n] = true;
  queue <pair <int,int>> q;
  q.push({n,0});
  while(!q.empty()){
	  auto [x,dist] = q.front();
	  if(x == 0){
		  ans = dist;
		  break;
	  } 
	  q.pop();
	  int temp;
	  if(x % 2 == 0)temp = x+1;
	  else temp = x-1;
	  if(!mapp[temp]){
		  mapp[temp] = true;
		  q.push({temp,dist+1});
	  }
	  temp = func(x);
	  if(!mapp[temp]){
		  mapp[temp] = true;
		  q.push({temp,dist+1});
	  }
  }
  cout << ans;
}
