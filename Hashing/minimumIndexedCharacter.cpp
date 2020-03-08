#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    string str, patt;
    cin >> str;
    cin >> patt;
    int i;
    unordered_map <char,int> m;
    for(i = 0; i < str.length(); i++){
      if(m.find(str[i]) == m.end()) m.insert(pair <char,int>(str[i],i));
    }
    bool found = false;
    char c;
    int minIndex = str.length();
    for(i = 0; i < patt.length(); i++){
      if(m.find(patt[i]) != m.end()){
        found = true;
        if(m[patt[i]] < minIndex){
          c = patt[i];
          minIndex = m[c];
        }
      }
    }
    if(!found) cout << "$\n";
    else cout << c << "\n";
  }
}
