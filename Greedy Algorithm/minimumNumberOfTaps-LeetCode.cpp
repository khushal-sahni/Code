// Problem statement: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define vi vector <int>
#define pi pair <int, int>
#define ff first
#define ss second
#define p(x) cout << #x << " " << (x) << "\n";

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        ++n;
        vector <pi> yay;
        rep(i,0,n){
          if(ranges[i] > 0) yay.emplace_back(max(i-ranges[i],0), min(i+ranges[i], n-1 ));
        }
        sort(yay.begin(),yay.end());
        int rightmost = 0, i = -1, ans = 0, yaysz = yay.size();
        while(rightmost < n-1){
          if(i >=yaysz){
            break;
          }
          int currmax = -1;
          while(i + 1 < yaysz && yay[i+1].ff <= rightmost){
            ++i;
            currmax = max(currmax, yay[i].ss);
          }
          ++ans;
          if(currmax > rightmost){
            rightmost = currmax;
          }
          else break;
        }
        if(rightmost >= n-1) return ans;
        return -1;
    }
};


int main(){
  int n = 5;
  vi ranges = { 3, 4, 1, 1, 0, 0};
  Solution obj;
  cout << obj.minTaps(n, ranges);
}
