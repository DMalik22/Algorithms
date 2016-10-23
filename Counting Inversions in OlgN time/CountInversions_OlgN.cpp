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

using namespace std;

int Sort_and_Count(vector<int>::iterator begin, vector<int>::iterator end){
    if (begin == end) return 0;
    
    //distance is a method from iterators library to count number of elements between to pointers/iterators
    //next is a method that takes is an iterator p and an integer n and returns the position of p if it were advanced by n positions
    vector<int>::iterator mid = next(begin, (distance(begin, end) / 2));
    
    int r_a = Sort_and_Count(begin, mid);
    int r_b = Sort_and_Count(++mid, end);
    
    int r_ab = Merge_and_Count(, begin_2);
    
    return (r_a + r_b + r_ab);
}

int main(int argc, const char * argv[]){
    
    if (argc != 2){
        cout << "Usage: ./Count_Inv <file_name>" << endl; //<file_name> refers to a file of integers where each line contains a number
        return EXIT_FAILURE;
    }
    
    ifstream infile(argv[1]);
    
    //to store store number in which inversions are being counted
    vector<int> numbers;
    int num;
    
    while(infile >> num){
        numbers.push_back(num);
    }
    
    int number_of_inversions = Sort_and_Count(numbers.begin(), numbers.end());

    cout << "Number of lines is " << number_of_inversions << endl;
    
    return EXIT_SUCCESS;
}