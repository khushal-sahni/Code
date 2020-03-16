
int minSwaps(int A[], int N){
  set <int> s;
  int i,B[N],count = 0;
  for(i = 0; i < N; i++) s.insert(A[i]);
  for(i = 0; i < N; i++) B[i] = distance(s.begin(),s.find(A[i]));
  for(i = 0; i < N; i++){
    while(i != B[i]){
      swap(A[i],A[B[i]]);
      swap(B[i],B[B[i]]);
      count++;
    }
  }
  return count;
}
