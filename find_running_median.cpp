//Used C++ STL priority queues
/*
 Given an input stream of n integers, you must perform the following task for each  integer:
 
 1. Add the ith integer to a running list of integers.
 2. Find the median of the updated list (i.e., for the first element through the ith element).
 3. Print the list's updated median on a new line. The printed value must be a double-precision number scaled to 1 decimal place (i.e., 12.3 format).
 
 Input Format
 
 The first line contains a single integer, n , denoting the number of integers in the data stream.
 Each line i of the n subsequent lines contains an integer, a_i , to be added to your list.
 
 Output Format
 
 After each new integer is added to the list, print the list's updated median on a new line as a single double-precision number scaled to 1 decimal place (i.e., 12.3 format).
 
 Sample Input
 
 6
 12
 4
 5
 3
 8
 7
 
 Sample Output
 
 12.0
 8.0
 5.0
 4.5
 5.0
 6.0
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
 Figured out the efficient approach here:
 https://www.youtube.com/watch?v=VmogG01IjYc
 http://en.cppreference.com/w/cpp/container/priority_queue
 */

class Solution {
  void addNumber(int number,
                 priority_queue<int> &lowers,
                 priority_queue<int, vector<int>, greater<int> > &highers){
    if (lowers.size() == 0 || number < lowers.top())
      lowers.push(number);
    else
      highers.push(number);
  }
  
  void rebalance(priority_queue<int> &lowers,
                 priority_queue<int, vector<int>, greater<int> > &highers){
    int bigger_arg = lowers.size() > highers.size() ? 1 : 2;
    
    if(bigger_arg == 1){
      if(lowers.size() - highers.size() > 1){
        highers.push(lowers.top());
        lowers.pop();
      }
    }
    else{
      if(highers.size() - lowers.size() > 1){
        lowers.push(highers.top());
        highers.pop();
      }
    }
  }
  
  double getMedian(priority_queue<int> &lowers,
                   priority_queue<int, vector<int>, greater<int> > &highers){
    if(highers.size() == 0) return lowers.top();
    if(lowers.size() == highers.size()){
      return (((double) (lowers.top() + highers.top())) / 2);
    }
    else{
      int bigger_arg = lowers.size() > highers.size() ? 0 : 1;
      if(bigger_arg == 0)
        return lowers.top();
      else
        return highers.top();
    }
  }
  
public:
  vector<double> return_Medians(vector<int> &a){
    priority_queue<int> lowers;
    priority_queue<int, vector<int>, greater<int> > highers;
    vector <double> medians;
    
    int length = a.size();
    for(int i = 0; i < length; i++){
      int num = a[i];
      addNumber(num, lowers, highers);
      rebalance(lowers, highers);
      medians.push_back(getMedian(lowers, highers));
    }
    return medians;
  }
};





int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int a_i = 0;a_i < n;a_i++){
    cin >> a[a_i];
  }
  cout << fixed << setprecision(1);
  Solution running_medians;
  vector<double> medians = running_medians.return_Medians(a);
  for(int m_i = 0;m_i < n;m_i++)
    cout << medians[m_i] << endl;
  
  return 0;
}
