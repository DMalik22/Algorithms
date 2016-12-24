/*
 Implemented a solution to a simple problem to find distance between 2 nodes in an
 undirected graph, returned -1 if there's no path between the 2 nodes.
 */

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int BFS_distance(vector<vector<int> > &adj, int s, int t) {
  vector <int> dist (adj.size(), -1); //all given distances are positive so no harm in initializing original distances vector to -1 instead of infinity
  dist[s] = 0;
  queue<int> Q;
  Q.push(s);
  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    
    for(int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i];
      if(dist[v] == -1){
        Q.push(v);
        dist[v] = dist[u] + 1;
      }
      if(v == t) break;
    }
    if (u == t) break;
  }
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << BFS_distance(adj, s, t);
}
