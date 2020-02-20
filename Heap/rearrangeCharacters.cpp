#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

void swim(vector <int> &arr, int i){
  while(i > 0 && arr[i]>arr[(i-1)/2]){
    swap(arr[i],arr[(i-1)/2]);
    i = (i-1)/2;
  }
}

void sink(vector <int> &arr, int i){
  int n = arr.size();
  while((2*i + 1) < n){
    int j = 2*i + 1;
    if(j < n-1 && arr[j] < arr[j+1]) j++;
    if(arr[i] < arr[j]) swap(arr[i],arr[j]);
    i = j;
  }
}

void makeHeap(vector <int> &arr){
  for(int i = 1; i < arr.size(); i++) swim(arr,i);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    int i,l;

    cin >> s;
    l = s.length();
    vector <int> v(26,0);
    vector <int> v2;
    for(i = 0; i < l; i++)v[s[i]-'a']++;
    for(i = 0; i < 26; i++) if(v[i] > 0) v2.push_back(v[i]);
    makeHeap(v2);

    while(v2.size() > 1){
      v2[1]--;
      if(v2[1] == 0) swap(v2[1],v2.back());
      sink(v2,1);
      if(v2.back() == 0) v2.pop_back();

      v2[0]--;
      if(v2[0] == 0) swap(v2[0],v2.back());
      sink(v2,0);
      if(v2.back() == 0) v2.pop_back();
    }
    if(v2[0] > 1) cout << "0\n";
    else cout << "1\n";
  }
}
