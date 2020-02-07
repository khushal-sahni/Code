#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkParantheses(string s1){
  int l = s1.length();
  stack <char> s;
  for(int i = 0; i < l; i++){
    char c = s1[i];
    if(c == '[' || c == '(' || c == '{') s.push(c);
    else{
      if(s.empty()) return false;
      if(c == ']' && s.top() != '[') return false;
      else if(c == ')' && s.top() != '(') return false;
      else if(c == '}' && s.top() != '{') return false;
      s.pop();
    }
  }
  if(s.empty()) return true;
  else return false;
}

int main(){
  int t;
  scanf("%d\n",&t );
  while(t--){
    string s1;
    cin >> s1;
    if(checkParantheses(s1)) cout << "balanced" << "\n";
    else cout << "not balanced" << "\n";
  }
}
