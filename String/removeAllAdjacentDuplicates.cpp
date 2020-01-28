#include <iostream>
#include <string>
using namespace std;

int lastIndex(string s1, int i){
  int j = 1;
  while(s1[i+j] == s1[i]) j++;
  return i+j-1;
}

void removeDuplicates(string s1){
  int l = s1.length();
  char c = '\n';
  int lastIndexx;
  bool foundDuplicate = false;

  for(int i = 0; i < s1.length();i++){
    if(s1[i] == c){
      foundDuplicate = true;
      lastIndexx = lastIndex(s1,i);
      if(lastIndexx < l-1) s1 = s1.substr(0,i-1) + s1.substr(lastIndexx+1,l-lastIndexx+1);
      else s1 = s1.substr(0,i-1);
      i--;
    }
    c = s1[i];
  }

  if(foundDuplicate) removeDuplicates(s1);
  else cout << s1 << "\n";
}



int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string s1;
    cin >> s1;
    removeDuplicates(s1);
  }
}
