//A naive approach to find the running median problem
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

#include <iomanip>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
As implemented in CLRS 
https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec04.pdf
*/

class Heap {
    //heap implemented as a tree using a (1 based index) array to store nodes 
    vector <int> A;

    //returns index of node's parent
    int parent(int i){
        return i / 2;
    }
    
    //returns index of node's left child
    int left(int i){
        return 2*i;
    }
    
    //returns index of node's right child
    int right(int i){
        return 2*i+ 1;
    }
    
    //correct a single violation of the heap property in a subtree at its root
    void min_heapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest;
        
        if(l <= A.size() - 1 && A[l] < A[i])
            smallest = l;
        else
            smallest = i;
        
        if(r <= A.size() - 1 && A[r] < A[smallest])
            smallest = r;
        
        if(smallest != i){
            iter_swap(A.begin() + i, A.begin() + smallest);
            min_heapify(smallest);
        }
    }
    
    
    //produce a max-heap from an unordered array
    void build_min_heap(){
        int n = A.size() - 1;
        for(int i = n /2; i >= 1; i++)
            min_heapify(i);
    }
    
    public:
    Heap(){
        A.push_back(0);
    }
    
    //insert new element at end of vector and build min heap
    void insert(int i){
        A.push_back(i);
        build_min_heap();
    }
    
    float return_median(){
    int n = A.size() - 1;
    if (n%2 == 0)
        return((((A[n / 2] + A[(n / 2) + 1]) / 2) * 10) / 10) ;
    else
        return((A[(n / 2) + 1] * 10) / 10);
    }
};

int main(){
    int n;
    cin >> n;
    int val;
    float median;
    Heap * A = new Heap();
    for(int i = 0;i < n;i++){
       cin >> val;
       A->insert(val);
       median = A->return_median();
       cout << median << setprecision(1) << endl;
    }
    
    
    return 0;
}


