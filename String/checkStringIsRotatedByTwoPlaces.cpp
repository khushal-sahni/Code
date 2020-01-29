#include <iostream>
#include <string>
using namespace std;

bool checkClockWise(string s1, string s2){
  int l1 = s1.length(), l2 = s2.length();
  if(l1 != l2) return false;
  for(int i = 0; i < l1-2; i++){
    if(s1[i] != s2[i+2]) return false;
  }
  if(s1[l1-2] != s2[0]) return false;
  if(s1[l1-1] != s2[1]) return false;
  return true;
}

bool checkAntiClockWise(string s1, string s2){
  int l1 = s1.length(), l2 = s2.length();
  if(l1 != l2) return false;
  for(int i = 2; i < l1; i++){
    if(s1[i] != s2[i-2]) return false;
  }
  if(s1[0] != s2[l1-2]) return false;
  if(s1[1] != s2[l1-1]) return false;
  return true;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string s1, s2;
    cin >> s1;
    cin >> s2;
    if(checkClockWise(s1,s2) || checkAntiClockWise(s1,s2)) cout << 1 << "\n";
    else cout << 0 << "\n";
  }
}
