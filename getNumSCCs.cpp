/*
 Implemented a solution to use dfs to count number of Strongly Connected Components in a Graph as explained in CLRS 21.4
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;

void Explore_SCC(int v, vector<vector<int> > &adj, vector<bool> &visited, list<int> &Order){
  visited[v] = true;
  
  for(int i = 0; i < adj[v].size(); i++){
    int w = adj[v][i];
    if(visited[w] == false){
      Explore_SCC(w, adj, visited, Order);
    }
  }
}

void dfs_SCC(vector<vector<int> > &G, list<int> &order, int &numSCCs){
  vector<bool> visited(G.size(), false);
  
  for(list<int>::const_iterator iterator = order.begin(), end = order.end(); iterator != end; ++iterator){
    int v = *iterator;
    if(!visited[v]){
      numSCCs++;
      Explore_SCC(v, G, visited, order);
    }
  }
}

void Explore(int v, vector<vector<int> > &adj, vector<bool> &visited, list<int> &Order){
  visited[v] = true;
  for(int i = 0; i < adj[v].size(); i++){
    int w = adj[v][i];
    if(visited[w] == false){
      Explore(w, adj, visited, Order);
    }
  }
  Order.push_front(v);
}

void dfs(vector<vector<int> > &adj, list<int> &Order){
  vector<bool> visited(adj.size(), false);
  for(int i = 0; i < adj.size(); i++){
    if(visited[i] == false){
      Explore(i, adj, visited, Order);
    }
  }
}

vector<vector<int> > getGraphTraspose(vector<vector<int> > &G){
  vector<vector<int> > G_transpose(G.size(), vector<int>());
  for(int i = 0; i < G.size(); i++){
    for(int j = 0; j < G[i].size(); j++){
      int x = i;
      int y = G[i][j];
      G_transpose[y].push_back(x);
    }
  }
  return G_transpose;
}

void SCC(vector<vector<int> > &Graph, int &numSCCs){
  list<int> order;
  
  dfs(Graph, order);
  
  vector<vector<int> > Graph_transpose = getGraphTraspose(Graph);
  
  dfs_SCC(Graph_transpose, order, numSCCs);
}


int number_of_strongly_connected_components(vector<vector<int> > &adj) {
  int result = 0;
  SCC(adj, result);
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
