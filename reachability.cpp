/*
 Used a DFS approach to determine if there's a path between 
 two vertices in the context of determining whether there's 
 a path to a given exit from a given location in a maze
 */

#include <iostream>
#include <vector>

using std::vector;

void Explore(int v, bool *visited, vector<vector<int> > &adj){
  visited[v] = true;
  for(int i = 0; i < adj[v].size(); i++){
    int w = adj[v][i];
    if (visited[w] == false){
      Explore(w, visited, adj);
    }
  }
}

int reach(vector<vector<int> > &adj, int x, int y) {
  bool * visited = new bool[adj.size()];
  Explore(x, visited, adj);
  if (visited[y] == true){
    return 1;
  }
  return 0;
}

int main() {
  size_t n, m; //n vertices, m edges
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y; //pari
    adj[x - 1].push_back(y - 1);
    //std::cout << "adj[" << x - 1 << "].push_back(" << y - 1  <<  ")\n";
    adj[y - 1].push_back(x - 1);
    //std::cout << "adj[" << y - 1 << "].push_back(" << x - 1 <<  ")\n\n";
  }
  int x, y;
  std::cin >> x >> y;//x -> location in maze, y -> location of exit
  std::cout << reach(adj, x - 1, y - 1);
}
