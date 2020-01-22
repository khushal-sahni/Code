#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,i;
    scanf("%d",&n);
    int arrivalTimes[n],departureTimes[n];
    for(i = 0; i < n; i++) scanf("%d",&arrivalTimes[i]);
    for(i = 0; i < n; i++) scanf("%d",&departureTimes[i]);
    multimap <int,char> trainMap;
    for(i = 0; i < n; i++) trainMap.insert(pair <int, char> (arrivalTimes[i],'a'));
    for(i = 0; i < n; i++) trainMap.insert(pair <int, char> (departureTimes[i],'d'));
    int count = 0,maxCount = 0;
    for(auto x = trainMap.begin(); x != trainMap.end(); x++) {
      if(x->second == 'a'){
        count++;
        maxCount = max(maxCount,count);
      }
      else count--;
    }
    printf("%d\n",maxCount);
  }
}
