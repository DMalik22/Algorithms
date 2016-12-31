/*
 Significantly improved earlier implementation of Bellman-Ford by better utilizing STL and OOP.
 
 The std::cout comments may be uncommented to visualize how the algorithm works.
 
 Right now the code returns 1 is a negative cycle is detected in the graph input:
 a directed graph with possibly negative edge weights.
 
 For example, for the input
 4 4 //n verices and m edges
 1 2 -5 // u, v, weight of edge from u to v
 4 1 2
 2 3 2
 3 1 1
 
 The algorithms returns 1.
 */

#include <iostream>
#include <vector>

const int max_weight = 1000;

using std::vector;

class Edge
{
  int v;
  int w;
  
public:
  Edge (int vertex, int weight) : v(vertex), w(weight) {}
  
  int vertex() const { return v; }
  int weight() const { return w; }
};

vector<int> InitializeSingleSource(vector<vector<Edge> > &G, int s){
  int infinity = max_weight + 1;
  
  vector <int> distance(G.size(), infinity);
  distance[s] = 0;
  
  return distance;
}

void Relax(int u, int v, int weight_edge_uv, vector<int> &distance){
  //  std::cout << "\tReceived Relax(" << u  + 1 << ", " << v + 1 << ", " << weight_edge_uv << ")\n";
  //  std::cout << "\tdistance[" << u + 1 << "] = " << distance[u] << ", distance[" << v + 1 << "] = " << distance[v] << ", weight of edge (" << u + 1 << ", "<< v + 1 << ") = " << weight_edge_uv << std::endl;
  //  std::cout << "is distance[" << v + 1 << "] >  (distance["  << u + 1 << "] + weight of edge (" << u + 1 << ", "<< v + 1 << ")) ?" << std::endl;
  if(distance[v] > (distance[u] + weight_edge_uv)){
    distance[v] = distance[u] + weight_edge_uv;
    //    std::cout << "\tTrue: " << "\tdistance[" << v + 1 << "] = " << distance[v];
  }
  //  else{
  //    std::cout << "\tFalse";
  //  }
  //  std::cout << std::endl;
}

int BellmanFord(vector<vector<Edge> > &G, int s){
  vector<int> distance = InitializeSingleSource(G, s);
  
  int numVertices = G.size();
  
  for(int k = 1; k < numVertices; k++){
    //    std::cout << "k = " << k << std::endl;
    for(vector< vector<Edge> >::size_type v = 0; v < G.size(); ++v)
    {
      for(vector<Edge>::size_type e = 0; e < G[v].size(); ++e)
      {
        //        std::cout << "Relax(" << v + 1 << ", " << G[v][e].vertex() + 1<< ", " << G[v][e].weight() << ")" << std::endl;
        Relax(v, G[v][e].vertex(), G[v][e].weight(), distance);
      }
    }
    //    std::cout << "---------------------------------\n";
  }
  
  for(vector< vector<Edge> >::size_type v = 0; v < G.size(); ++v)
  {
    for(vector<Edge>::size_type e = 0; e < G[v].size(); ++e)
    {
      if(distance[G[v][e].vertex()] > (distance[v] + G[v][e].weight()))
        //graph contains negative cycle
        return 0;
    }
  }
  return 1;
}

int is_there_a_negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  
  //Figured out this approach from https://ece.uwaterloo.ca/~cmoreno/ece250/2012-03-26--graphs-implementation.pdf
  vector<vector<Edge> > adjacencies(adj.size(), vector<Edge>());
  
  for(int i = 0; i < adj.size(); i++){
    for(int j = 0; j < adj[i].size(); j++){
      int u = i;
      int v = adj[i][j];
      int w = cost[i][j];
      adjacencies[u].push_back(Edge(v, w));
    }
  }
  
  if (BellmanFord(adjacencies, 0) == 0)
    return 1;
  
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
  std::cout << is_there_a_negative_cycle(adj, cost);
}
