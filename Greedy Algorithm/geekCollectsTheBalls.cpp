#include <iostream>

using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,m,i,j;
    long int sum = 0, fsum = 0, ssum = 0;
    cin >> n >> m;
    int firstLine[n], secondLine[m];
    for(i = 0; i < n; i++) cin >> firstLine[i];
    for(i = 0; i < m; i++) cin >> secondLine[i];

    i = 0, j = 0;
    while(i < n && j < m){
      if(firstLine[i] < secondLine[j]){
        fsum += firstLine[i];
        i++;
      }
      else if(firstLine[i] > secondLine[j]){
        ssum += secondLine[j];
        j++;
      }
      else{
        if(i < n-1 && firstLine[i+1] == firstLine[i] && fsum > ssum){
          fsum += firstLine[i];
          i++;
          continue;
        }
        if(j < m-1 && secondLine[j+1] == secondLine[j] && ssum > fsum){
  
          ssum += secondLine[j];
          j++;
          continue;
        }

        if(fsum > ssum) sum += fsum;
        else sum += ssum;

        fsum = 0;
        ssum = 0;
        sum += firstLine[i];

        i++;
        j++;

      }
    }
    while(i < n){
      fsum += firstLine[i];

      i++;
    }
    while(j < m){
      ssum += secondLine[j];
      j++;
    }
    if(fsum > ssum) sum += fsum;
    else sum += ssum;
    cout << sum << "\n";
  }
}
