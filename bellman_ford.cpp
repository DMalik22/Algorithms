/*
 Implemented Bellman-Ford. Will make implementation more elegant.
 */
#include <iostream>
#include <vector>
#include <limits>
using std::vector;

bool Bellman_Ford(vector<vector<int> > &adj, vector<vector<int> > &weight, int s){
  //InitializeSingleSource(adj, s)
  int infinity = std::numeric_limits<int>::max();
  vector <int> distance(adj.size(), infinity);
  distance[s] = 0;
  int numVertices = adj.size();
  int numVertices_minus_one = adj.size() - 1;
  
  //Relaxing edges |V| - 1 times
  for(int k = 1; k <= numVertices_minus_one; k++){
    for(int i = 0; i < numVertices - 1; i++){
      for(int j = 0; j < adj[i].size(); j++){
        int u = i;
        int v = adj[i][j];
        int w = weight[i][j];
        if(distance[v] > (distance[u] + w)){
          distance[v] = distance[u] + w;
        }
      }
    }
  }
  
  //Checking to see if any distance value is updated on |V|th iteration of Relax procedure
  for(int i = 0; i < adj.size(); i++){
    for(int j = 0; j < adj[i].size(); j++){
      int u = i;
      int v = adj[i][j];
      int w = weight[i][j];
      if(distance[v] > (distance[u] + w))
        return false;
    }
  }
  return true;
}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  for(int i = 0; i < adj.size(); i++){
    if(Bellman_Ford(adj, cost, i) == false){
      return 1; //negative cycle detected
    }
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
