/*
In this program, based on 2 inputs- n, number of ints in an array, and an array of n ints,
 I build a heap, sorted in ascending order, and print the number of swaps I did, as well aa
 the indices of the elements that I swapped.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;
  int LastValidIndex = 0;
  
  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();
    BuildHeap();
  }

  int Parent(int i){
    return ((i - 1) / 2);
  }
  
  int LeftChild(int i){
    return (2*i + 1);
  }
  
  int RightChild(int i){
    return (2*i + 2);
  }
  
  void BuildHeap(){
    LastValidIndex  = data_.size() - 1;
    for (int i = LastValidIndex/2; i >= 0; i--)
      SiftDown(i);
  }
  
  void SiftDown(int i){
    int minIndex = i;
    int l = LeftChild(i);
    if (l <= LastValidIndex && data_[l] < data_[minIndex])
      minIndex = l;
    int r = RightChild(i);
    if (r <= LastValidIndex && data_[r] < data_[minIndex])
      minIndex = r;
    if (i != minIndex){
      if (minIndex == l)
        swaps_.push_back(make_pair(l, i));
      else
        swaps_.push_back(make_pair(r, i));
      swap(data_[i], data_[minIndex]);
      SiftDown(minIndex);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
