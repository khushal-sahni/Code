#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxLen(int A[],int n){
  unordered_map <int, int> m;
  m.clear();
  int sum = 0;
  int maxLength = 0;
  for(int i = 0; i < n; i++){
    sum += A[i];
    if(sum == 0) maxLength = max(maxLength,i+1);
    if(m.find(sum) != m.end()) maxLength = max(maxLength,(i-m[sum]));
    else m.insert(pair <int,int>(sum,i));
  }
  return maxLength;
}


int main(){
  int arr[900];
  memset(arr,0,sizeof(arr));
  // int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
  cout << maxLen(arr,900);
}
