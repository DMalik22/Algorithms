/*
 Implemented Prim's algorithm, as explained in CLRS, to solve the problem of connecting 
 all cities on a map by building roads connecting them all such that the distance between 
 any two cities and the total length of the road network are optimized.
 
 The cities are input as conventional cartesian coordinates on a map.
 
 Sample input:

 5       //number of cities
 0 0     //(x, y) coordinates of a city
 0 2
 1 1
 3 0
 3 2
 
 Output:
 7.064495102    //The total length of the optimized road network.
 */
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>

//Based on the given problem constraints.

const double max_weight = sqrt(2 * pow(1000000, 2));

using std::vector;
using std::sqrt;
using std::pair;
using std::make_pair;

inline double get_distance(pair<int, int> point1, pair<int, int> point2){
  return sqrt(double(pow((point1.first - point2.first), 2) + pow((point1.second - point2.second),2)));
}

double distance_of_route(vector<int> &route, vector<pair<int, int> > &Vertices){
  double distance = 0.;
  int u, v;
  
  for(int i = 1; i < route.size(); i++){
    distance += get_distance(Vertices[i], Vertices[route[i]]);
  }
  
  return distance;
}

double getMin(vector<vector<double> > &Weight, vector<bool> &isVertexinQ){
  double min = max_weight + 1;
  int minIndex = 0;
  
  for(int i = 0; i < Weight.size(); i++){
    if(isVertexinQ[i]){
    if(Weight[i][0] < min){
      minIndex = i;
      min = Weight[i][0];
    }
  }
  }
  return minIndex;
}

vector<int> MST_Prim(vector<vector<double> > &adjMatrix, int root){
  double infinity = max_weight + 1;
  
  vector <double> key(adjMatrix.size(), infinity);
  vector <int> parent(adjMatrix.size(), -1); //let -1 be NILL
  key[root] = 0.;
  
  vector<bool> isVertexinQ(adjMatrix.size(), true);
  int verticesProcessed = 0;
  
  vector<vector<double> > Q(adjMatrix.size(), vector<double>());
  
  for(int v = 0; v < adjMatrix.size(); v++)
    Q[v].push_back(key[v]);
  
  while(verticesProcessed != adjMatrix.size()){

    int u = getMin(Q, isVertexinQ);
    isVertexinQ[u] = false;
    verticesProcessed++;
    
    for(int v = 0; v < adjMatrix[u].size(); v++){
      if(isVertexinQ[v] && u != v){
        if(adjMatrix[u][v] < key[v]){
          parent[v] = u;
          key[v] = adjMatrix[u][v];
          Q[v][0] = key[v];
        }
      }
    }
  }
  
  return parent;
}

double minimum_distance_of_road_network(vector<int> x, vector<int> y) {
  double result = 0.;
  
  //Vertices are the (x, y) coordinates given as input
  vector<pair<int, int> > Vertices(x.size());
  
  for(int i = 0; i < x.size(); i++)
    Vertices[i] = (make_pair(x[i], y[i]));
  
  int n = x.size();
  if(n == 1) return 0;
  vector<vector<double> > adjMatrix(n, vector<double>(n, 0));
  
  for(int u = 0; u < n; u++){
    for(int v = 0; v < n; v++){
      adjMatrix[u][v] = get_distance(Vertices[u], Vertices[v]);
    }
  }
  
  vector<int> shortest_route = MST_Prim(adjMatrix, 0);
  
  return distance_of_route(shortest_route, Vertices);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance_of_road_network(x, y) << std::endl;
  return 0;
}