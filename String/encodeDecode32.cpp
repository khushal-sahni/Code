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
#define pll pair <lli,lli>
#define vi vector <int>
#define vl vector <lli>
#define p(x) cout << #x << " is " << (x) << " on Line:" << __LINE__ << " \n";
#define pl(x) for(auto &y:x) cout << y << " "; cout << "\n";
#define ppl(x) for(auto &y:x) cout << y.ff << " " << y.ss << " | ";cout << "\n";
#define um unordered_map

string charset32 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
map <char,int> reverseMap;

string encode32(string s){
	int l = s.size();
	int left = l%5;
	if(left){
		for(int i = 0; i < (5-left); ++i) s += string (1,0);
	}
	vector <string> vec;
	for(int i = 0; i < (int)s.size(); ++i){
		vec.eb((bitset <8> ( s[i] )).to_string());
	}
	vector <char> ans;
	for(int i = 0; i < (((int)vec.size())*8); i += 5){
		string temp = "";
		for(int j = 0; j < 5; ++j){
			int pos = i + j;
			temp += vec[pos/8][pos%8];
		}
		int index = (bitset<5> (temp)).to_ulong();
		ans.eb(charset32[index]);
	}
	int rem = 0;
	if(left) rem = (40 - (left*8))/5;
	int sz = ans.size();
	for(int i = 0; i < rem; ++i){
		ans[sz-1-i] = '=';
	}
	string finalAns ((int)ans.size(),0);
	for(int i = 0; i < (int)ans.size(); ++i){
		finalAns[i] = ans[i];
	}
	return finalAns;
}

string decode32(string s){
	int count = 0;
	for(int i = (int)s.size()-1; i >= 0; --i){
		if(s[i] == '=')++count;
		else break;
	}
	s = s.substr(0, s.size()-count);
	vector <string> vec;
	for(int i = 0; i < (int)s.size(); ++i){
		vec.eb( bitset<5> ( reverseMap[s[i]] ).to_string()  );
	}
	vector <char> ans;
	for(int i = 0; i + 7 < (((int)vec.size()) * 5); i += 8){
		string temp = "";
		for(int j = 0; j < 8; ++j){
			int pos = i + j;
			temp += vec[pos/5][pos%5];
		}
		ans.eb( bitset<8> (temp).to_ulong() );
	}
	string finalAns(ans.size(), 0);
	for(int i = 0; i < (int)ans.size(); ++i){
		finalAns[i] = ans[i];
	}
	return finalAns;
	
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  cout << encode32(s);
  for(int i = 0; i < 32; ++i) reverseMap[charset32[i]] = i;
  cout << "\n" << decode32(encode32(s));
}
