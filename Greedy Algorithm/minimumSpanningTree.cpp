struct edge{
  int start,end,weight;
};

bool comp(edge a, edge b){
  return a.weight < b.weight;
}

int root(int a, int parent[]){
  while(parent[a] != a) a = parent[a];
  return a;
}

void connect(int a, int b, int parent[], int sizeOfTree[]){
  a = root(a, parent);
  b = root(b, parent);
  if(sizeOfTree[a] < sizeOfTree[b]){
    parent[a] = b;
    sizeOfTree[b] += sizeOfTree[a];
  }
  else{
    parent[b] = a;
    sizeOfTree[a] += sizeOfTree[b];
  }
}

bool connected(int a, int b, int parent[]){
  return (root(a, parent) == root(b, parent));
}

int spanningTree(int V,int E,vector<vector<int> > graph)
{
    int i,j,sum = 0, counter = 0;
    vector <edge> v;
    for(i = 0; i < V; i++){
      for(j = 0; j < V; j++){
        if(graph[i][j] != INT_MAX){
          edge e = {i,j,graph[i][j]};
          v.push_back(e);
        }
      }
    }
    sort(v.begin(),v.end(),comp);

    int parent[V], sizeOfTree[V];
    for(i = 0; i < V; i++){
      parent[i] = i;
      sizeOfTree[i] = 1;
    }

    for(i = 0; i < v.size(); i++){
      edge e = v[i];
      if(!connected(e.start,e.end, parent)){
        sum += e.weight;
        counter++;
        connect(e.start,e.end, parent, sizeOfTree);
        if(counter == V-1) break;
      }
    }
    return sum;
}
