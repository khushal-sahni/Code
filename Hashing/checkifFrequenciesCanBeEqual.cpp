#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int possibleOrNot(string s){
  unordered_map <char,int> m;
  for(int i = 0; i < s.length(); i++){
    if(m.find(s[i]) == m.end()) m.insert(pair <char,int>(s[i],1));
    else m[s[i]]++;
  }
  unordered_map <int,int> n;
  for(auto k = m.begin(); k != m.end(); k++){
    if(n.find(k->second) == n.end()) n.insert(pair <int,int>(k->second,1));
    else n[k->second]++;
  }
  if(n.size() > 2) return 0;
  if(n.size() < 2) return 1;
  if(n.begin()->second == 1 &&(n.begin()->first == 1 || (n.begin()->first) - ((++n.begin())->first) == 1 )) return 1;
  if((++n.begin())->second == 1 &&( (++n.begin())->first == 1  || ((++n.begin())->first) - (n.begin()->first) == 1)) return 1;
  return 0;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    cout << possibleOrNot(s) << "\n";
  }
}
