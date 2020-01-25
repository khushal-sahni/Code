#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

void printPermutations(string s1, int l,int arr[], string s2){
  if(s2.length() == l) cout << s2 << " ";
  else{
    for(int i = 0; i < l; i++){
      if(!arr[i]){
        arr[i] = 1;
        printPermutations(s1,l,arr,s2+s1[i]);
        arr[i] = 0;
      }
    }
  }
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string s1;
    cin >> s1;
    int l = s1.length();
    int arr[l];
    memset(arr,0,sizeof(arr));
    sort(s1.begin(),s1.end());
    printPermutations(s1,l,arr,"");
    printf("\n");
  }
}
