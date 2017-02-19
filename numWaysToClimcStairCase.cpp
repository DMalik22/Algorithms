/*
Davis has n staircases in his house and he likes to climb each staircase 1, 2, or 3 steps at a time. Being a very precocious child, he wonders how many ways there are to reach the top of the staircase.

Given the respective heights for each of the  staircases in his house, find and print the number of ways he can climb each staircase on a new line.

Input Format

The first line contains a single integer, s, denoting the number of staircases in his house.
Each line  of the  subsequent lines contains a single integer, n, denoting the height of staircase .

Sample Input
3
1
3
7

 Sample Output
1
4
44

 Explanation
1 way ro climb a staircase if height 1
1 + 1 + 1, 1 + 2, 2 + 1, 3 -> total 4 ways to climb staircase of height 3
 */

#include <iostream>
using namespace std;

int num_of_ways(int n){
  if(n <= 0 ) return 0;
  if(n == 1) return 1;
  int count = 0;
  int numWays[3] = {1, 1, 2};
  for(int i = 3; i <= n; i++){
    count = numWays[0] + numWays[1] + numWays[2];
    numWays[0] = numWays[1];
    numWays[1] = numWays[2];
    numWays[2] = count;
  }
  return count;
}

int main(){
  int s;
  cin >> s;
  for(int a0 = 0; a0 < s; a0++){
    int n;
    cin >> n;
    cout <<  num_of_ways(n) << endl;
  }
  
  return 0;
}

