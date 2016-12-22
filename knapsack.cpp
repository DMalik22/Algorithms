/*
This is my dynamic programming solution for a generic knapsack without repetitions problem.

The intput is:
Capacity of knapsack  Number of goldbars
Weight of each gold bar

For example: 3 goldbars that weigh 1, 4 and 8 units must be chosen to fit in a knapsack 
 such that the value, i.e., in this case, total weight of selected gold bars is maximum
 within the bounds of the maximum weight that the knapsack can carry

10 3
1 4 8

The correct output for this problem is 9 (1 + 8)

The 3 commented std::cout lines can be uncommented to see the resultant matrix, where 
 value(ith_goldbar, weight) is the maximum value achievable using a knapsack of weight 'weight' and item 1, ..., 'ith_goldbar'
 */

#include <iostream>
#include <vector>
#include <algorithm> 

using std::vector;

int optimal_weight(int Capacity, const vector<int> &weight_of_gold_bar){
  vector <vector <int> > value(weight_of_gold_bar.size() + 1, vector <int> (Capacity + 1, 0));

  for(int ith_goldbar = 1; ith_goldbar <= weight_of_gold_bar.size(); ith_goldbar++){
    for(int weight = 1; weight <= Capacity; weight++){
      
      value[ith_goldbar][weight] = value[ith_goldbar - 1][weight];
      int weight_of_ith_gold_bar = weight_of_gold_bar[ith_goldbar - 1];
      if (weight_of_ith_gold_bar <= weight){ //weight_of_gold_bar[ith_goldbar - 1] because weight_of_gold_bar is a zero based vector, so a goldbar in ith column of value matrix is at the i - 1 'th position in  weight_of_gold_bar
        int val = value[ith_goldbar - 1][weight - weight_of_ith_gold_bar] + weight_of_ith_gold_bar;
        
        if (value[ith_goldbar][weight] < val){
          value[ith_goldbar][weight] = val;
        }
      }
//      std::cout << ith_goldbar << "," << weight << " -> ";
//      std::cout << value[ith_goldbar][weight] << "\t";
    }
//    std::cout << "\n";
  }  
  return value[weight_of_gold_bar.size()][Capacity];
}


int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
