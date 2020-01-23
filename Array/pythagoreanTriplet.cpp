#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool checkTriplets(int arr[], int n){
  int i,j;
  sort(arr,arr+n);
  for(i = 0; i < n-1; i++){
    unordered_set <int> s;
    for(j = n-1; j > i; j--){
      if(s.find( (arr[i]* arr[i]) + (arr[j]*arr[j]) ) != s.end()) return true;
      else s.insert(arr[j] * arr[j]);
    }
  }
  return false;
}

int main(){
  int t;
  scanf("%d",&t );
  while(t--){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);
    if(checkTriplets(arr,n)) printf("Yes\n");
    else printf("No\n");
  }
}
