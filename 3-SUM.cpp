#include <iostream>
#include <unordered_set>
using namespace std;

void findTriplets(int arr[], int n){

  for(int i = 0; i < n; i++){

    unordered_set <int> s;

    for(int j = i; j < n; j++){ //if you don't want same number repeated start from i+1 and initial loop ends at n-2 instead of n-1
      if(s.find(-(arr[i]+arr[j])) != s.end()){
        cout << -(arr[i]+arr[j]) << " " << arr[i] << " " << arr[j] << "\n";
      }
      else{
        s.insert(arr[j]);
      }
    }
  }

}

int main(){
  int arr[] = {0,-1,3,4,9,2,-7};
  int n = sizeof(arr)/sizeof(arr[0]);
  findTriplets(arr, n);
}
