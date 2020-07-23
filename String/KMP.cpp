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
#define p(x) cout << #x << " is " << (x) << " on Line:" << __LINE__ << " \n";

void buildLps(int lps[], string &pat){
	int len = 0,i = 1;
	lps[0] = 0;
	while(i < (int)pat.length()){
		if(pat[i] == pat[len]){
			++len;
			lps[i] = len;
			++i;
		}
		else{
			if(len != 0){
				len = lps[len-1];
			}
			else {
				lps[i] = 0;
				++i;
			}
		}
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  string s,pat;
  cin >> s >> pat;
  int lps[(int)pat.length()];
  buildLps(lps,pat);
  for(int i = 0, j = 0; i < (int)s.length();){
	  if(s[i] == pat[j]){
		  ++i;
		  ++j;//
		  if(j == (int)pat.length()){
			  cout << i - (int)pat.length() << " " << i-1<< "\n";
			  j = lps[j-1];//
		  }
	  }
	  else{
		  if(j == 0){
			  ++i;
		  }
		  else j = lps[j-1];
	  }
  }
}
