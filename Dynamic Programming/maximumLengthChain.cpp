bool comp(val a, val b){
  if(a.second < b.second) return true;
  else if(a.second > b.second) return false;
  else if(a.first < b.first) return true;
  else return false;
}

int maxLengthChain(int i, int chainLength[], val p[], int n){
  if(chainLength[i] != 0) return chainLength[i];
  int j = i+1;
  while(j < n && p[i].second >= p[j].first ) j++;
  if(j != n) return chainLength[i] = 1 + maxLengthChain(j, chainLength, p, n);
  else return chainLength[i] = 1;
}

int maxChainLen(struct val p[],int n)
{
  sort(p,p+n,comp);
  int maxLength = 0;
  int chainLength[n] = {0};
  for(int i = 0; i < n; i++){
    maxLength = max(maxLength,maxLengthChain(i,chainLength,p, n));
  }
  return maxLength;
}
