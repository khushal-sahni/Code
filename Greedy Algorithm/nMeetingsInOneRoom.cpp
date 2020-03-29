#include <iostream>
#include <algorithm>
using namespace std;

struct activity{
  int starting,ending,i;
};

bool comp(activity a, activity b){
  return a.ending < b.ending;
};

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,i,count = 0, lastActivityFinishingTime = -1;
    cin >> n;
    int starting[n], ending[n];
    activity arr[n];
    for(i = 0; i < n; i++) cin >> starting[i];
    for(i = 0; i < n; i++) cin >> ending[i];
    for(i = 0; i < n; i++){
      activity a = {starting[i],ending[i],i};
      arr[i] = a;
    }
    sort(arr,arr+n,comp);
    for(i = 0; i < n; i++){
      if(arr[i].starting > lastActivityFinishingTime){
        count++;
        lastActivityFinishingTime = arr[i].ending;
        cout << (arr[i].i)+1 << " ";
      }
    }
    cout << "\n";
  }
}
