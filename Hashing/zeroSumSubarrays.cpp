
#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i;
    cin >> n;
    long int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    long int sum = 0;
    int counter = 0;
    int d;
    unordered_map  <long int, int> s;
    for(i = 0; i < n; i++){
      sum += arr[i];
      if(s.find(sum) != s.end()) d = s[sum];
      else d = 0;
      if(arr[i] == 0 || sum == 0) counter++;
      if(arr[i] == 0 && sum != 0) counter += (d-1);
      else counter += d;
      if(d == 0) s.insert(pair <long int, int>(sum,1));
      else s[sum]++;
    }
    cout << counter << "\n";
  }
}
