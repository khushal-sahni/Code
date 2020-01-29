#include <iostream>
#include <string>
#include <map>
using namespace std;

bool checkAnagram(string s1, string s2){
  map <char,int> s1_map;
  map <char,int> s2_map;
  int l1 = s1.length(), l2 = s2.length(),i;
  if(l1 != l2) return false;
  for(i = 0; i < 26; i++){
    s1_map.insert(pair <char,int>( (char)('a'+i),0 ));
    s2_map.insert(pair <char,int>( (char)('a'+i),0 ));
  }
  for(int i = 0; i < l1; i++) s1_map[s1[i]]++;
  for(int i = 0; i < l2; i++) s2_map[s2[i]]++;

  for(auto x = s1_map.begin(),y = s2_map.begin(); x != s1_map.end(); x++,y++){
    if(x->second != y->second) return false;
  }
  return true;

}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string s1,s2;
    cin >> s1 >> s2;
    if(checkAnagram(s1,s2)) cout << "YES"<< "\n";
    else cout << "NO" << "\n";
  }
}
