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
#define vl vector <lli>
#define p(x) cout << #x << " is " << (x) << " on Line:" << __LINE__ << " \n";
#define pl(x) for(auto &y:x) cout << y << " "; cout << "\n";


int xorr(int i){
	if(i%4 == 0) return i;
	else if(i % 4 == 1) return 1;
	else if(i % 4 == 2) return i+1;
	else return 0;
}

int func(int l, int r){
	int temp = 0;
	for(int i = l; i <= r; ++i) temp ^= i;
	return temp;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int x;
  cin >> x;
  int counter = 0;
  vector <pi> errors;
  while(x--){
	  int l = rand()%1000;
	  int r = rand()%1000;
	  r += l;
	  if(func(l,r) != (xorr(r)^xorr(l-1)) ) errors.eb(l,r);
	  else ++counter;
  }
  cout << "correct answers " << counter << "\n";
  cout << "wrong answers " << errors.size() << "\n";
  for(auto &fuck: errors) cout << fuck.ff << " " << fuck.ss << "\n";
}
