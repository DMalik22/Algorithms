/*
 Input: The first line contains the number of vertices n. The second line contains n integer numbers from 1 to n-1. Each number in this line is the parent of vertex i,
 where i is 0 based indexed of the numbers in the second line. The root is indicate by -1.
 
 For example,
 the input
 5
 4 -1 4 1 1
 
 means that there are 5 nodes in total. Parent of 0 is 4, root is 1, parent of 2 is 4, parent of 3 is 1 parent of 4 is 1.
 
 My task is to compute the height of this tree and display it.
 
 Note: The trees are any arbitrary trees, i.e., not neccessarily binary.
 
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


class TreeHeight {
  //the inputs I get
  int n;
  std::vector<int> parent;
  
  //Storing tree in 2d array
  std::vector< std::vector<int> > tree;
  //root is indicated by -1 so I am storing it in an independent variable
  int root;

  void initialize_tree(){
    tree.resize(n);
    for (int i = 0; i < parent.size(); i++){
      int p = parent[i];
      
      if (p == -1)
        root = i;
      else
        tree[p].push_back(i);
    }
  }
  
  //Used only for dugging. Must not use at the same time as compute_height as this will lead to erroneous results(becuase tree will be initialized twice)
  void print_tree_as_it_is_stored_in_memory(){
    initialize_tree();
    for (int i = 0; i < tree.size() ; i++){
      std::cout << i << ": ";
      for(int j = 0; j < tree[i].size(); j++){
        std::cout << tree[i][j]<< ", ";
      }
      std::cout << std::endl;
    }
  }
  
public:
  void read() {
    std::cin >> n;
    parent.resize(n);
    
    for (int i = 0; i < n; i++)
      std::cin >> parent[i];
  }
  
  void print_parent(){
    for (int i = 0; i < parent.size() ; i++)
      std::cout << parent[i] << ", ";
    std::cout << std::endl;
  }
  
  //the basic idea is to do BFS and increment height everytime the BFS leads to a new level
  int compute_height() {
    initialize_tree();
    int height = 0;
    
    std::queue<int> Nodes;
    Nodes.push(root);
    
    while(!Nodes.empty()){
      //counter to track number of nodes on a level
      //important, because this is how I keep track of whether I have traversed an entire level or not before updating the height
      int number_of_nodes_on_this_level = Nodes.size();
      
      for (int i = number_of_nodes_on_this_level; i > 0; i --){
        int p = Nodes.front();
        Nodes.pop();
        for (int i = 0; i < tree[p].size(); i++){
          Nodes.push(tree[p][i]);
        }
      }
      
      height++;
    }
    return height;
  }
  

};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  int h = tree.compute_height();
  std::cout << h << std::endl;
}
