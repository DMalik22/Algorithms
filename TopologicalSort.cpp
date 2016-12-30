/*
 Implemented Topological sort exactly as explained in CLRS.
 Works perfectly for all test cases now.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using std::vector;
using std::list;

void dfs_vist(int v, vector<vector<int> > &adj, bool * visited, list<int> &Order){
  visited[v] = true;
  for(int i = 0; i < adj[v].size(); i++){
    int w = adj[v][i];
    if(visited[w] == false){
      dfs_vist(w, adj, visited, Order);
    }
  }
  Order.push_front(v);
}

void dfs(vector<vector<int> > &adj, list<int> &Order){
  bool * visited = new bool[adj.size()];
  for(int i = 0; i < adj.size(); i++){
    if(visited[i] == false){
      dfs_vist(i, adj, visited, Order);
    }
  }
}

list<int> toposort(vector<vector<int> > adj) {
  list<int> order;
  dfs(adj, order);
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
  
  list<int> order = toposort(adj);
  
  for(list<int>::const_iterator iterator = order.begin(), end = order.end(); iterator != end; ++iterator){
    std::cout << *iterator + 1 << " ";
  }
  std::cout << std::endl;
}
