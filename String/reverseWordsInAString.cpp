#include <iostream>
#include <string>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string s1,s2;
    cin >> s1;
    int startingPosition, endingPosition = s1.length()-1;
    for(int i = (s1.length()-1); i >= 0; i--){
      if(s1[i] == '.'){
        startingPosition = i+1;
        s2 += s1.substr(startingPosition,endingPosition+1-startingPosition);
        endingPosition = i-1;
        s2+='.';
      }
    }
    s2 += s1.substr(0,endingPosition+1);
    cout << s2 << "\n";
  }
}
