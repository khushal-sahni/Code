#include <iostream>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(i = 0; i < m; i++) for(j = 0; j < n; j++) scanf("%d",&arr[i][j]);
    for(i = 0; i < n; i++) printf("%d ",arr[0][i]);
    int addI = 1,addJ = -1,counter = 0,countTotal = n, total = m*n;
    i = 0,j = n-1;
    n--,m--;
    while(true){
      while(counter < m){
        i += addI;
        countTotal++;
        printf("%d ",arr[i][j]);
        counter++;
      }
      m--; addI = -addI;
      counter = 0;
      while(counter < n){
        j += addJ;
        countTotal++;
        printf("%d ",arr[i][j]);
        counter++;
      }
      n--; addJ = -addJ;
      counter = 0;
      if(countTotal >= total) break;
    }
    printf("\n");
  }
}
