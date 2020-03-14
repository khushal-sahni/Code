void dfs(int i, int j, void *ptr, vector <int> A[],  int N, int M ){
  bool (*visited)[M] = static_cast <bool (*)[M]>(ptr);
  visited[i][j] = true;
  if(i < N-1){
    if(A[i+1][j] == 1 && !visited[i+1][j]) dfs(i+1,j,visited,A,N,M);
    if(j < M-1 && A[i+1][j+1] == 1 && !visited[i+1][j+1]) dfs(i+1,j+1,visited,A,N,M);
    if(j > 0 && A[i+1][j-1] == 1 && !visited[i+1][j-1]) dfs(i+1,j-1,visited,A,N,M);
  }
  if(i > 0){
    if(A[i-1][j] == 1 && !visited[i-1][j]) dfs(i-1,j,visited,A,N,M);
    if(j < M-1 && A[i-1][j+1] == 1 && !visited[i-1][j+1]) dfs(i-1,j+1,visited,A,N,M);
    if(j > 0 && A[i-1][j-1] == 1 && !visited[i-1][j-1]) dfs(i-1,j-1,visited,A,N,M);
  }
  if(j < M-1 && A[i][j+1] == 1 && !visited[i][j+1]) dfs(i,j+1,visited,A,N,M);
  if(j > 0 && A[i][j-1] == 1 && !visited[i][j-1]) dfs(i,j-1,visited,A,N,M);
}

int findIslands(vector<int> A[], int N, int M) {
  int count = 0;
  bool visited[N][M] = {0};
  memset(visited,0,sizeof(visited));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(!visited[i][j] && A[i][j] == 1){
        dfs(i,j,visited,A,N,M);
        count++;
      }
    }
  }
  return count;
}
1
4 7
1 1 1 1 0 0 1 1 0 1 0 1 1 0 0 0 0 0 1 0 1 1 0 0 0 1 1 1
