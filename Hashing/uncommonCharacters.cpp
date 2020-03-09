#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    string s1, s2;
    cin >> s1;
    cin >> s2;
    unordered_set <char> set1,set2;
    int i;
    for(i = 0; i < s1.length(); i++) set1.insert(s1[i]);
    for(i = 0; i < s2.length(); i++) set2.insert(s2[i]);
    set <char> s;
    for(i = 0; i < s1.length(); i++) if(set2.find(s1[i]) == set2.end()) s.insert(s1[i]);
    for(i = 0; i < s2.length(); i++) if(set1.find(s2[i]) == set1.end()) s.insert(s2[i]);
    for(auto k = s.begin(); k != s.end(); k++) cout << (*k);
    cout << "\n";
  }
}
