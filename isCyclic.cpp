/*
 Detected if a given directed graph is cyclic by modifying
 generic DFS to explore neighbors of a given vertex to also 
 keep track, when DFS was initiated for a particular vertex,
 of whether a neighbor found was already traveresed
 */

#include <iostream>
#include <vector>

using std::vector;

void Explore(int v, vector<vector<int> > &adj, bool * visited, bool * wasTraversed, bool &flag){
  if(flag == false){
  visited[v] = true;
  wasTraversed[v] = true;
  for(int i = 0; i < adj[v].size(); i++){
    int w = adj[v][i];
    if (visited[w] == false){
      Explore(w, adj, visited, wasTraversed, flag);
    }
    else if (visited[w] && wasTraversed[w]){
//      std::cout << "Cycle detected";
      flag = true;
      break;
    }
  }
  wasTraversed[v] = false;
  }
}

int isCyclic(vector<vector<int> > &adj) {
  bool * visited = new bool[adj.size()];
  bool * wasTraversed = new bool[adj.size()];
  bool cycleExists = false;
  for(int i = 0; i < adj.size(); i++){
    Explore(i, adj, visited, wasTraversed, cycleExists);
  }
  if (cycleExists){
    return 1;
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << isCyclic(adj);
}
