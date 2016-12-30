/*
 Improved earlier implementation by using a stack, thus, making it vastly simpler. Right now, gives wrong output for a few test cases.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

void postvisit(int v, int &clock, vector<int> &postvisit_order){
  postvisit_order[v] = ++clock;
}

void Explore(int v, vector<vector<int> > &adj, bool * visited, stack<int> &Order){
  visited[v] = true;
  for(int i = 0; i < adj[v].size(); i++){
    int w = adj[v][i];
    if(visited[w] == false){
      Explore(w, adj, visited, Order);
    }
  }
  Order.push(v);
}

void dfs(vector<vector<int> > &adj, stack<int> &Order){
  bool * visited = new bool[adj.size()];
  for(int i = 0; i < adj.size(); i++){
    if(visited[i] == false){
      Explore(i, adj, visited, Order);
    }
  }
}

stack<int> toposort(vector<vector<int> > adj) {
  stack<int> order;
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
  stack<int> order = toposort(adj);
  while(!order.empty()){
    std::cout << order.top() + 1 << " ";
    order.pop();
  }
}
