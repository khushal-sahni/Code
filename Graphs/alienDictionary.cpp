void toposort(string &ans, int s, vector <bool> &visited, int k, void *ptr ){
  bool (*graph)[k] = static_cast <bool (*)[k]>(ptr);
  visited[s] = true;
  for(int i = 0; i < k; i++){
    if(!visited[i] && graph[s][i]) toposort(ans, i, visited, k, graph);
  }
  ans += (char)(s+97);
}

string printOrder(string dict[], int N, int k) {
    bool graph[k][k];
    int i,j;
    memset(graph, 0, sizeof(graph));

    for(i = 1; i < N; i++){
      int l = (dict[i].length() < dict[i-1].length()) ? dict[i].length(): dict[i-1].length();
      for(j = 0; j < l; j++) if(dict[i][j] != dict[i-1][j]) break;
      if(j != l) graph[dict[i][j]-'a'][dict[i-1][j]-'a'] = true;
    }

    string ans = "";
    vector <bool> visited(k,0);
    for(i = 0; i < k; i++){
      if(!visited[i]) toposort(ans, i, visited, k, graph);
    }
    return ans;
}
