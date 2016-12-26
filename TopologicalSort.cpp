/*
 Implemented topological sort. Right now, gives wrong output for a few test cases.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

void postvisit(int v, int &clock, vector<int> &postvisit_order){
  postvisit_order[v] = ++clock;
}

void Explore(int v, vector<vector<int> > &adj, bool * visited, int &clock, vector<int> &postvisit_order){
  visited[v] = true;
  for(int i = 0; i < adj[v].size(); i++){
    int w = adj[v][i];
    if(visited[w] == false){
      Explore(w, adj, visited, clock, postvisit_order);
    }
  }
  postvisit(v, clock, postvisit_order);
}

void dfs(vector<vector<int> > &adj, vector<int> &postvisit_order){
  bool * visited = new bool[adj.size()];
  int clock = 0;
  for(int i = 0; i < adj.size(); i++){
    if(visited[i] == false){
      Explore(i, adj, visited, clock, postvisit_order);
    }
  }
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> order(adj.size(), 0);
  dfs(adj, order);
  std::reverse(order.begin(), order.end());
  return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] << " ";
  }
}
