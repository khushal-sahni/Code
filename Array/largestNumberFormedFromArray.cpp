#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compareFunction(int a, int b){
  string firstString = to_string(a)+to_string(b);
  string secondString = to_string(b)+to_string(a);
  return firstString>secondString;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d",&arr[i]);
    sort(arr,arr+n,compareFunction);
    string answer;
    for(i = 0; i < n; i++) answer += to_string(arr[i]);
    cout << answer << "\n";
  }
}
