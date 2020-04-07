#include <iostream>
using namespace std;

struct box{
  int height,width,length;
};

bool comp(box a, box b){
  return (a.width * a.length)>(b.width * b.length);
}

int mHeight(int i, int n, int dp[], vector <box> v){
  if(dp[i] != 0) return dp[i];
  int j = i + 1;
  int val = 0;
  while(j < 3*n){
    if(v[j].width < v[i].width && v[j].length < v[i].length) val = max(val,mHeight(j,n,dp,v));
    j++;
  }
  return dp[i] = v[i].height + val;
}

int maxHeight(int height[],int width[],int length[],int n)
{
    int i, j = 0, ans = 0;
    box b;
    vector <box> v(3*n);
    for(i = 0; i < n; i++){ // maintaning width smaller than length
      b = {height[i],min(length[i],width[i]),max(length[i],width[i])};
      v[j] = b;
      j++;
      b = {width[i],min(length[i],height[i]),max(length[i],height[i])};
      v[j] = b;
      j++;
      b = {length[i],min(height[i],width[i]),max(height[i],width[i])};
      v[j] = b;
      j++;
    }
    sort(v.begin(),v.end(),comp);
    int dp[3*n] = {0};
    for(i = 0; i < 3*n; i++){
      ans = max(ans,mHeight(i,n,dp,v));
    }
    return ans;
}
