/*
 Implemented a straightforward DP solution to the edit_distance problem as learnt in a MOOC
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

int edit_distance(const string &A, const string &B) {
  //comparing A[1...n] and B[1...m]
  int n = str1.size();
  int m = str2.size();
  
  vector<vector<int> > D(m + 1, vector<int>(n + 1));
  
  for(int i = 0; i <= m; i++)
    D[i][0] = i;
  for(int j = 0; j <= n; j++)
    D[0][j] = j;
  
  int insertion, deletion, match, mismatch;
  
  for(int j = 1; j <= m; j++){
    for(int i = 1; i <= n; i++){
      insertion = D[i][j - 1] + 1;
      deletion = D[i - 1][j] + 1;
      match = D[i - 1][j - 1];
      mismatch = D[i - 1][j - 1] + 1;
      
      if(str1[i - 1] == str2[j - 1])
        D[i][j] = std::min(std::min(insertion, deletion), match);
      else
        D[i][j] = std::min(std::min(insertion, deletion), mismatch);
    }
  }
  
  return D[n][m];
}

int main() {
  string A;
  string B;
  std::cin >> A >> B;
  std::cout << edit_distance(A, B) << std::endl;
  return 0;
}
