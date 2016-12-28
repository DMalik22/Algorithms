#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::pair;
using std::priority_queue;
using std::greater;
using std::make_pair;

vector<int> InitializeSingleSource(vector<vector<int> > &G, int s){
  int infinity = std::numeric_limits<int>::max();
  
  vector <int> distance(G.size(), infinity);
  distance[s] = 0;
  
  return distance;
}

void Relax(int u, int v, vector<vector<int> > &weight, vector<vector<int> > &G, vector<int> &distance, priority_queue< pair<int, int>,
           vector<pair<int,int> >,
           greater<pair<int, int> > > &Q){
  int weight_of_edge_uv, j;
  for(j = 0; j < G[u].size(); j++){
    if(G[u][j] == v)
      break;
  }
  weight_of_edge_uv = weight[u][j];
  
  if(distance[v] > (distance[u] + weight_of_edge_uv)){
    distance[v] = distance[u] + weight_of_edge_uv;
    Q.push(make_pair(distance[v], v));
  }
}

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //to store distance from source to target
  vector <int> dist = InitializeSingleSource(adj, s);
  
  //STL min heap initialization
  // Source: http://en.cppreference.com/w/cpp/container/priority_queue
  //         http://www.cplusplus.com/reference/functional/greater/
  priority_queue< pair<int, int>,
  vector<pair<int,int> >,
  greater<pair<int, int> > > Q;
  
  Q.push(make_pair(0, s));
  
  while(!Q.empty()){
    int u = Q.top().second;
    Q.pop();
    
    for(int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i];
      Relax(u, v, cost, adj, dist, Q);
      
      //      if(v == t)
      //        break;
    }
  }
  
  return dist[t];
  
  //  for(int i = 0; i < cost.size(); i++){
  //    std::cout << i + 1 << "-> ";
  //    for(int j = 0; j < cost[i].size(); j++){
  //      std::cout << adj[i][j] + 1 << "'s weight is " << cost[i][j] << "; ";
  //    }
  //    std::cout << "\n";
  //  }
  
  //  Input:
  //  4 4
  //  1 2 1
  //  4 1 2
  //  2 3 2
  //  1 3 5
  //  1 3
  //  Output:
  //  1-> 2's weight is 1; 3's weight is 5;
  //  2-> 3's weight is 2;
  //  3->
  //  4-> 1's weight is 2;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}

