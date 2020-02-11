#include <iostream>
#include <queue>
using namespace std;

int timeToRot(void *ptr, int r, int c){
  int i,j;
  int (*arr)[c] = static_cast<int (*)[c]>(ptr);
  queue <pair<int,int>> x;
  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++){
      if(arr[i][j] == 2) x.push(pair<int,int>(i,j));
    }
  }
  if(x.empty()) return -1;

  x.push(pair<int,int>(-1,-1));
  int time = 0;
  bool found = false;
  pair <int, int> var;
  while(!x.empty()){
    var = x.front();
    if(var.first == -1){
      if(!found) break;
      found = false;
      x.push(pair<int,int>(-1,-1));
    }
    else{
      i = var.first;
      j = var.second;
      if(j != c-1 && arr[i][j+1] == 1){
        arr[i][j+1] = 2;
        if(!found) time++;
        found = true;
        x.push(pair<int,int>(i,j+1));
      }
      if(j != 0 && arr[i][j-1] == 1){
        arr[i][j-1] = 2;
        if(!found) time++;
        found = true;
        x.push(pair<int,int>(i,j-1));
      }
      if(i != 0 && arr[i-1][j] == 1){
        arr[i-1][j] = 2;
        if(!found) time++;
        found = true;
        x.push(pair<int,int>(i-1,j));
      }
      if(i != r-1 && arr[i+1][j] == 1){
        arr[i+1][j] = 2;
        if(!found) time++;
        found = true;
        x.push(pair<int,int>(i+1,j));
      }
    }
    x.pop();

  }
  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++){
      if(arr[i][j] == 1) return -1;
    }
  }
  if(time != 0) return time;
  else return -1;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int r,c,i,j;
    scanf("%d %d",&r,&c);
    int arr[r][c];
    for(i = 0; i < r; i++){
      for(j = 0; j < c; j++){
        scanf("%d",&arr[i][j] );
      }
    }
    cout << timeToRot(arr,r,c) << "\n";
  }
}

// doesn't work for 1111
//
// #include <iostream>
// #include <climits>
// #include <algorithm>
// using namespace std;
//
// int minDistance(int i, int j, void *ptr,int c, void *ptr1, int r);
//
// void func(int i, int j, int r, int c, void *ptr, void *ptr1, int p, int q){
//   int (*minimumDistance)[c] = static_cast<int (*)[c]>(ptr);
//   int (*arr)[c] = static_cast<int (*)[c]>(ptr1);
//   if(arr[i+p][j+q] == 2) minimumDistance[i][j] = 1;
//   else if(arr[i+p][j+q] == 1) minimumDistance[i][j] = min(minimumDistance[i][j],1+minDistance(i+p,j+q,minimumDistance,c,arr,r));
// }
//
// int minDistance(int i, int j, void *ptr,int c, void *ptr1, int r){
//   int (*minimumDistance)[c] = static_cast<int (*)[c]>(ptr);
//   int (*arr)[c] = static_cast<int (*)[c]>(ptr1);
//   if(minimumDistance[i][j] != INT_MAX) return minimumDistance[i][j];
//   if(j != c-1) func(i,j,r,c,minimumDistance,arr,0,1);
//   if(j != 0) func(i,j,r,c,minimumDistance,arr,0,-1);
//   if(i != 0) func(i,j,r,c,minimumDistance,arr,-1,0);
//   if(i != r-1) func(i,j,r,c,minimumDistance,arr,1,0);
//   if(minimumDistance[i][j] == INT_MAX) return minimumDistance[i][j]-1;
//   return minimumDistance[i][j];
// }
//
// int main(){
//   int t;
//   scanf("%d\n",&t);
//   while(t--){
//     int r,c,i,j;
//     scanf("%d %d",&r,&c);
//     int arr[r][c],minimumDistance[r][c];
//     for(i = 0; i < r; i++){
//       for(j = 0; j < c; j++){
//         scanf("%d",&arr[i][j]);
//         minimumDistance[i][j] = INT_MAX;
//       }
//     }
//     int ans = 0;
//     for(i = 0; i < r; i++){
//       for(j = 0; j < c; j++){
//         if(arr[i][j] == 1) ans = max(ans,minDistance(i,j,minimumDistance,c,arr,r));
//       }
//     }
//     if(ans == INT_MAX || ans == INT_MAX-1) cout << -1 << " ";
//     else cout << ans << " ";
//     cout << "\n";
//   }
// }
