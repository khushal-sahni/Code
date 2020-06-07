#include<bits/stdc++.h>
using namespace std;
using li = long int;
using lli  = long long int;

#define eb emplace_back
#define mt make_tuple
#define mp make_pair

struct node{
	bool isLeaf;
	int num;
	unordered_map <char,node*> map;
	node(){
		isLeaf = false;
		num = 0;
	};
};

void insert(node *&head, string &s){
	//base case for no head
	auto curr = head;
	for(int i = 0; i < s.length(); ++i){
		if(curr->map.find(s[i]) == curr->map.end()){
			auto x = new node();
			curr->map[s[i]] = x;
			
		}
		
		curr = curr->map[s[i]];
		
	}
	curr->isLeaf = true;
}

int exists(node *&head, string &s){
	auto curr = head;
	for(int i = 0; i < s.length(); ++i){
		if(curr->map.find(s[i]) == curr->map.end()){
			return -1;
		}
		curr = curr->map[s[i]];
	}
	if(curr->isLeaf == false) return -1;
	++(curr->num);
	return curr->num;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  int n;
  string s;
  cin >> n;
  auto head = new node();
  while(n--){
	  cin >> s;
	  auto x = exists(head,s);
	  if(x == -1){
		  cout << "OK\n";
		  insert(head,s);
	  }
	  else{
		  s += to_string(x);
		  cout << s << "\n";
		  insert(head,s);
	  }
  }
}
