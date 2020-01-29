#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string s1;
    cin >> s1;
    int sum = 0, l = s1.length();
    char c = '\n';
    map <char, int> roman;
    roman.insert(pair<char,int>('I',1));
    roman.insert(pair<char,int>('V',5));
    roman.insert(pair<char,int>('X',10));
    roman.insert(pair<char,int>('L',50));
    roman.insert(pair<char,int>('C',100));
    roman.insert(pair<char,int>('D',500));
    roman.insert(pair<char,int>('M',1000));

    for(int i = 0; i < l; i++){
      if(roman[s1[i]] > roman[c]){
        sum -= 2*roman[c];
      }
      sum += roman[s1[i]];
      c = s1[i];
    }
    cout << sum << "\n";
  }
}
