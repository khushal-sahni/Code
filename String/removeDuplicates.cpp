#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
  int t;
  scanf("%d\n",&t); // this extra \n here because getline reads it if not present and can become empty
  while(t--){
    string s1,s2="";
    getline(cin,s1);
    set <char> duplicateFinder;
    int l = s1.length();
    for(int i = 0; i < l; i++){
      if(duplicateFinder.find(s1[i]) == duplicateFinder.end()){
        s2 += s1[i];
        duplicateFinder.insert(s1[i]);
      }
    }
    cout << s2 << "\n";
  }
}
