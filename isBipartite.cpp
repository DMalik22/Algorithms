/*
 Used BFS to determine if graph is bipartite. Failing one test case. Otherwise works fine.
 */

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int is_bipartite(vector<vector<int> > &adj) {
  vector <int> color (adj.size(), -1); // -1 represents no color
  int s = adj[0][0]; //arbitrarilty choosing this as a source vertex
  color[s] = 0; //let 0 represent white and 1 black
  queue<int> Q;
  Q.push(s);
  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    
    for(int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i];
      
      //if v has no color, then color it differently than its ancestor
      if(color[v] == -1){
        Q.push(v);
        if(color[u] == 0) color[v] = 1;
        if(color[u] == 1) color[v] = 0;
      }
      //else check if v and its ancestor have same color
      //if this is the case then the graph is not bipartite
      else{
        if(color[u] == color[v])
          //graph is not bipartite
          return 0;
      }
    }
  }
  
  //graph is bipartite
  return 1;
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
  std::cout << is_bipartite(adj);
}
