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

void swim(int key, vi &heap){
	if(key == 0) return;
	int parent = (key-1)/2;
	if(heap[parent] > heap[key]) swap(heap[parent],heap[key]);
	swim(parent,heap);
}

int rightmost(int key, int n){
	if(key*2 + 2 >= n) return key;
	return rightmost(key*2 + 2,n);
}

int predecessor(int key, int n){
	if(key*2 + 1 >= n){//leaf
		int parent = (key-1)/2;
		if(parent*2 + 1 == key){//left child
			return (parent-1)/2;//parent of parent assuming it exists
		}
		else{//right child
			return parent;
		}
	}
	else{
		return rightmost(key*2+1,n);
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector <int> heap(n);
  for(auto &x: heap) cin >> x;
  for(int i = 0; i < n; ++i) swim(i,heap);
  int pos = -1;
  for(int i = 0; i < n; ++i) if(heap[i] == 50) pos = i;
  cout << heap[predecessor(pos,n)];
}
