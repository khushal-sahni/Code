#include <iostream>
#include <string>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string characters;
    cin >> characters;
    int i = 0, lastIndex = -1;
    for(auto x = characters.begin(); x != characters.end(); x++){
      if(*x == '1') lastIndex = i;
      i++;
    }
    printf("%d\n",lastIndex);
  }
}
