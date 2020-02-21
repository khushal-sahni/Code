#include <iostream>
using namespace std;

void floodFill(void * ptr, int n,int m, int x, int y, int k){
  int (*arr)[m] = static_cast<int (*)[m]>(ptr);
  int d = arr[x][y];
  arr[x][y] = k;
  if(y < m-1 && arr[x][y+1] == d) floodFill(arr,n,m,x,y+1,k);
  if(y > 0 && arr[x][y-1] == d) floodFill(arr,n,m,x,y-1,k);
  if(x < n-1 && arr[x+1][y] == d) floodFill(arr,n,m,x+1,y,k);
  if(x > 0 && arr[x-1][y] == d) floodFill(arr,n,m,x-1,y,k);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,m,i,j,x,y,k;
    cin >> n >> m;
    int arr[n][m];
    for(i = 0; i < n; i++) for(j = 0; j < m; j++) cin >> arr[i][j];
    cin >> x >> y >> k;
    floodFill(arr,n,m,x,y,k);
    for(i = 0; i < n; i++) for(j = 0; j < m; j++) cout << arr[i][j] << " ";
    cout << "\n";
  }
}
