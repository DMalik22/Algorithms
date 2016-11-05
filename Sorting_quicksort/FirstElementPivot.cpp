//
//  compilation command -> g++ Karatsuba_multiplication.cpp -o Karatsuba_multiplication
//
//  Algorithms
//
//  Stanford's Algorithms specialization on Coursera
//  Course 1 Week 1 Programming Assignment
//
//  Implementation as understood from: https://courses.csail.mit.edu/6.006/spring11/exams/notes3-karatsuba
//  Additional references: https://en.wikipedia.org/wiki/Karatsuba_algorithm#Pseudocode
//                         http://www.cplusplus.com/reference/vector/vector/
//
//
//  Created by Deetpanshu Malik on 10/15/16.
//  Copyright © 2016 Deetpanshu Malik. All rights reserved.
//

//You should not count comparisons one-by-one. Rather, when there is a recursive call on a subarray of length m, you should simply add m−1 to your running total of comparisons. (This is because the pivot element is compared to each of the other m−1 elements in the subarray in this recursive call.)
//


#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void print(vector<int> A){
    for(vector<int>::iterator i = A.begin(); i != A.end(); i++)
        cout << *i << " ";
    cout<<endl;
}

//vector<int>::iterator Partition(vector<int>::iterator l, vector<int>::iterator r){
//    int x = *l;
//    vector<int>::iterator i = l + 1;
//    for(vector<int>::iterator j = l + 1; j < r; j++){
//        if(*j < x){
//            iter_swap(j, i);
//            i++;
//        }
//    }
//    iter_swap(l, (i - 1));
//    return i - 1;
//}
//
//void QuickSort(vector<int>::iterator l, vector<int>::iterator r){
//    if (distance(l, r) <= 1) return;
//    vector<int>::iterator p = Partition(l, r);
//    QuickSort(l, p - 1);
//    QuickSort(l + distance(l, p), r);
//}

void QuickSort(vector<int>& A, int n){
    if (n <= 1) return;
    
    int p = Partition(A, )
}

int main(int argc, const char * argv[]){
    if (argc != 2){
        cout << "Usage: ./Sort <file_name>" << endl; //<file_name> refers to a file of integers where each line contains a number
        return EXIT_FAILURE;
    }
    
    ifstream infile(argv[1]);
    
    //to store store number in which inversions are being counted
    vector<int> A;
    int num;
    while(infile >> num){
        A.push_back(num);
    }
    //print(numbers);
    int n = 0;
    print(A);
    QuickSort(vector<int> A, 0, A.size() - 1);
    print(A);
    //cout << n << endl;
    return EXIT_SUCCESS;
}