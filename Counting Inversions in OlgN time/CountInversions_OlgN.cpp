//
//  compilation command -> g++ CountInversions_OlgN.cpp -o Count_Inv
//  usage-> ./Count_Inv file_of_integers
//
//  Algorithms
//
//  Stanford's Algorithms specialization on Coursera
//  Course 1 Week 2 Programming Assignment
//
//  Implementation as understood from: Stanford's Divide and Conquer,
//  Sorting and Searching, and Randomized Algorithms class on Coursera
//
//  Additional references: https://www.cs.princeton.edu/~wayne/kleinberg-tardos/pdf/05DivideAndConquerI.pdf
//                         http://www.cplusplus.com/reference/vector/vector/
//
//  Not using STL's merge subroutine, implementing my own
//  Using STL containers and iterators
//
//  Created by Deetpanshu Malik on 10/23/16.
//  Copyright © 2016 Deetpanshu Malik. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>

using namespace std;

void print(vector<int> A){
    for(auto i = A.begin(); i != A.end(); i++)
        cout << *i << " ";
    cout<<endl;
}


void Merge(vector<int>& A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    cout << "/////////////////"<< endl;
    cout << "p = " << p << ", q = " << q << ", r = " << r << ", n1 = " << n1 << ", n2 = " << n2 << endl;
    vector<int> L(n1+1);
    vector<int> R(n2+1);
    
    int i, j, k;
    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    
    cout << "L - > ";
    print(L);
    
    for (j = 0; i < n2; j++)
        R[j] = A[q + j + 1];
    
    cout << "R - > ";
    print(R);
    
    L[n1] = numeric_limits<int>::max();
    R[n2] = numeric_limits<int>::max();
    
    i = 0;
    j = 0;
    k = p;
    
    while(i < n1 && j < n2)
    {
        if (R[j] < L[i]) {
            A[k++] = R[j++];
        }
        else {
            A[k++] = L[i++];
        }
    }
    while(i < n1)
    {
        A[k++] = L[i++];
    }
    while(j < n2)
    {
        A[k++] = R[j++];
    }

    cout << "A - > ";
    print(A);
    cout << "/////////////////"<< endl;
}

void Merge_Sort(vector<int>& A, int p, int r){
    cout << "p = " << p << ", r = " << r << endl;
    
    if (p < r){
        int q = (p + r) / 2;
        Merge_Sort(A, p, q);
        cout << "After call on 1st half" << endl;
        print(A);
        Merge_Sort(A, q + 1, r);
        cout << "After call on 2nd half" << endl;
        print(A);
        Merge(A, p, q, r);
    }
    
    cout << "Before returning" << endl;
    print(A);
    cout << endl;

}

int main(int argc, const char * argv[]){
    
    if (argc != 2){
        cout << "Usage: ./Count_Inv <file_name>" << endl; //<file_name> refers to a file of integers where each line contains a number
        return EXIT_FAILURE;
    }
    
//    ifstream infile(argv[1]);
//    
//    //to store store number in which inversions are being counted
//    vector<int> numbers;
//    int num;
//    
//    while(infile >> num){
//        numbers.push_back(num);
//    }
    
    //int number_of_inversions = Sort_and_Count(numbers, 0, numbers.size() - 1);
    vector<int> numbers = {2, 4, 5, 7, 1, 2, 3, 6};
     Merge_Sort(numbers, 0, 7);
    print(numbers);
    //cout << "Number of lines is " << number_of_inversions << endl;
    
    return EXIT_SUCCESS;
}
