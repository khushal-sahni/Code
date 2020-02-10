#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(){
  int t;
  scanf("%d\n",&t);
  while(t--){
    int n,i;
    scanf("%d",&n);
    char arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    map <char, int> x;
    queue <char> y;
    for(char c = 'a'; c <= 'z'; c++) x.insert(pair <char, int>(c,0));
    for(i = 0; i < n; i++){
      y.push(arr[i]);
      x[arr[i]]++;
      while(!y.empty() && x[y.front()] >= 2) y.pop();
      if(y.empty()) cout << "-1 ";
      else cout << y.front() << " ";
    }
    cout << "\n";
  }
}
