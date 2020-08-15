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

struct node{
	int start,end,len,sufflink; 
	unordered_map <char,int> edge;
};

int curr,ptr;
string s;

void insert(int ind, vector <node> &tree){
	int temp = curr;
	while(true){
		int l = tree[temp].len;
		if(ind-l-1 >= 0 && s[ind] == s[ind-l-1]) break;//>=1 means a guy exists 
		temp = tree[temp].sufflink;
	}
	if(tree[temp].edge.find(s[ind]) != tree[temp].edge.end()){
		curr = tree[temp].edge[s[ind]];
		return;
	}
	++ptr;
	tree[temp].edge[s[ind]] = ptr;
	tree[ptr].len = tree[temp].len + 2;
	tree[ptr].end = ind;
	tree[ptr].start = ind- tree[ptr].len + 1;
	
	temp = tree[temp].sufflink;//need to move one down can't have itself as the suffix link
	curr = ptr;
	if(tree[curr].len == 1){
		tree[curr].sufflink = 1;//1 is 0 indexed it refers to the second root 
		return;
	}
	while(true){
		int l = tree[temp].len;
		if(ind - l -1 >=0 && s[ind] == s[ind-l-1]) break;
		temp = tree[temp].sufflink;
	}
	tree[curr].sufflink = tree[temp].edge[s[ind]];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  int l = s.length();
  vector <node> tree(l+2);
  tree[0].len = -1, tree[0].sufflink = tree[1].len = tree[1].sufflink = 0;
  ptr = 1; //to track which pos to add new node to
  curr = 0; 

	for (int i=0; i<l; i++) 
		insert(i,tree); 

	// printing all of its distinct palindromic substring
	cout << "All distinct palindromic substring for "
		<< s << " : \n"; 
	for (int i=2; i<=ptr; i++) 
	{ 
		cout << i-1 << ") "; 
		for (int j=tree[i].start; j<=tree[i].end; j++) 
			cout << s[j]; 
		cout << endl; 
	} 
}

//Here you can see the first node acts as default fallback node for character edges 
// the second node acts as the default fallback node for suff link

