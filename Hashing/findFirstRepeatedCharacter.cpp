#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

string firstRepeat(string s){
  unordered_set <char> charSet;
  for(int i = 0; i < s.length(); i++){
    if(charSet.find(s[i]) != charSet.end()){
      string charString(1,s[i]);
      return charString;
    }
    charSet.insert(s[i]);
  }
  return "-1";
}

int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    cout << firstRepeat(s) << "\n";
  }
}
