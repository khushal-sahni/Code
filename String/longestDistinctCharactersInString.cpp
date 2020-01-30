#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int findLongest(string s1){
  int l = s1.length();
  unordered_map <char,int> coolMap;
  int currentCount = 0, bestCount = 0;

  for(int i = 0; i < l; i++){
    if(coolMap.find(s1[i]) == coolMap.end()){
      coolMap.insert(pair<char,int>(s1[i],i));
      currentCount ++;
      bestCount = max(bestCount, currentCount);
    }
    else{
      if(coolMap[s1[i]] < (i-currentCount)){
        coolMap[s1[i]] = i;
        currentCount++;
        bestCount = max(bestCount, currentCount);
      }
      else{
        currentCount = (i - coolMap[s1[i]]);
        coolMap[s1[i]] = i;
      }
    }
  }
  cout << bestCount << "\n";
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    string s1;
    cin >> s1;
    findLongest(s1);
  }
}
