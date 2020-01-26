#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool checkPalindrome(string s1, int i, int j,int n, void *x){
  bool (*isPalindrome)[n] = static_cast<bool (*)[n]>(x);
  if(i < j){
    if(s1[i] == s1[j]){
      if(i+1 == j || isPalindrome[i+1][j-1])  return isPalindrome[i][j] = true;
      else return false;
    }
    else return false;
  }
  else return isPalindrome[i][j] = true;
}

void findPalindrome(string s1,int n, void *x){
  bool (*isPalindrome)[n] = static_cast<bool (*)[n]>(x);
  int length = 0, beginningPosition = -1, endingPosition = -1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n-i; j++){
      if(checkPalindrome(s1,j,j+i,n,isPalindrome) && i+1 > length){
        length = i+1;
        beginningPosition = j;
        endingPosition = j+i;
      }
    }
  }
  cout << s1.substr(beginningPosition,endingPosition+1-beginningPosition) << "\n";
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string s1;
    cin >> s1;
    int n = s1.length();
    bool isPalindrome[n][n];
    memset(isPalindrome,0,sizeof(isPalindrome));
    findPalindrome(s1,n,isPalindrome);
  }
}
