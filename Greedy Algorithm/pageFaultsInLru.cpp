#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i, capacity, pageFaults = 0;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    cin >> capacity;
    map <int,int> indexValue;
    unordered_map <int,int> valueIndex;

    for(i = 0; i < n; i++){
      if(valueIndex.find(arr[i]) == valueIndex.end()){
        if(valueIndex.size() >= capacity){
          int value = indexValue.begin()->second;
          indexValue.erase(indexValue.begin());
          valueIndex.erase(value);
        }
        indexValue.insert(make_pair(i,arr[i]));
        valueIndex.insert(make_pair(arr[i],i));

        pageFaults++;
      }
      else{
        int index = valueIndex[arr[i]];
        valueIndex[arr[i]] = i;
        indexValue.erase(index);
        indexValue.insert(make_pair(i,arr[i]));
      }
    }
    cout << pageFaults << "\n";

  }
}
