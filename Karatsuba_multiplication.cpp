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

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    if (argc != 3)
        cout << "Usage: ./Karatsuba_multiplication number1 number2" << endl;
    
    else{
        string number1 = argv[1];
        string number2 = argv[2];
        
        vector<char> n1(number1.begin(), number1.end());
        vector<char>::iterator iter;
        vector<int> num1;
        vector<int>::iterator iter2;
        
        for (iter = n1.begin(); iter != n1.end(); iter++)
            num1.push_back((static_cast<int>((*iter) - '0')));
        
        for (iter2 = num1.begin(); iter2 != num1.end(); iter2++)
            cout << (*iter2);
        
        cout << endl;
        
        
    }
    return 0;
}
