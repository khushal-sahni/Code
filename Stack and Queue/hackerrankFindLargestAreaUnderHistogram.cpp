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

int maxArea(vi &histo){
	stack <int> st;
	int n = histo.size(), ans = 0,prev;
	for(int i = 0; i < n; ++i){
		if(st.empty() || histo[st.top()] <= histo[i])st.push(i);
		else{
			while(histo[st.top()] > histo[i]){
				auto ind = st.top();
				st.pop();
				if(st.empty()) prev = -1;
				else prev = st.top();
				ans = max(ans, histo[ind] * (i-prev-1) );
				
			}
		}
	}
	while(!st.empty()){
		auto ind = st.top();
		st.pop();
		if(st.empty()) prev = -1;
		else prev = st.top();
		ans = max(ans, histo[ind] * (n-prev-1));
	}
	return ans;
}


int func1(vi &histo){
    int n = histo.size();
    vi l(n,-1), r(n,n);
    stack <int> st;
    for(int i = 0;i < n; ++i){
        while( ! st.empty() && histo[st.top()] >= histo[i]) st.pop();
        if(!st.empty())l[i] = st.top();
        st.push(i);
    }
    st = stack <int> ();
    for(int i = n-1; i >= 0; --i){
        while( !st.empty() && histo[st.top()] >= histo[i]) st.pop();
        if(!st.empty())r[i] = st.top();
        st.push(i);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        auto temp = histo[i] * (r[i]-l[i]-1);
        if(temp > ans) ans = temp;
    }
    return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi v(n);
  for(auto &x: v) cin >> x;
  cout << func1(v) << " " << maxArea(v);// two ways to write the same solution 
}



