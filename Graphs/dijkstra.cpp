
struct edge{
  int origin,end,weight;
};

auto comp = [](edge a, edge b){
  return (a.weight > b.weight);
};

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    unordered_set <int> s;
    priority_queue <edge, vector <edge>, decltype(comp)> q(comp);
    int distances[V];
    for(int i = 0; i < V; i++){
      distances[i] = INT_MAX;
      edge e = {src,i,INT_MAX};
      q.push(e);
    }
    distances[src] = 0;
    edge e = {src,src,0};
    q.push(e);
    while(s.size() < V){
      auto minimum = q.top();
      s.insert(minimum.end);
      for(int i = 0; i < V; i++){
        if( graph[minimum.end][i] != 0 && s.find(i) == s.end() && distances[minimum.end] + graph[minimum.end][i] < distances[i] ){
          distances[i] = distances[minimum.end] + graph[minimum.end][i];
          edge e = {minimum.end,i,distances[i]};
          q.push(e);
        }
      }
      q.pop();
    }
    for(int i = 0; i < V; i++) cout << distances[i] << " ";
}
