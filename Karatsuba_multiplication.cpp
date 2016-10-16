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

vector<int> getNumber(string input){
    vector<char> n(input.begin(), input.end());
    vector<int> num;
    
    for (auto iter = n.begin(); iter != n.end(); iter++)
        num.push_back((static_cast<int>((*iter) - '0')));

    return num;
}

void display(const vector<int>& number){
    for (auto iter = number.begin(); iter !=number.end(); iter++)
        cout << (*iter);
    cout << endl;
}

void make_same_size(vector<int>& number1, vector<int>& number2){
    int size1 = number1.size();
    int size2 = number2.size();
    
    if (size1 > size2){
        int to_pad = size1 - size2;
        number2.insert(number2.begin(), to_pad + 1, 0);
        number1.insert(number1.begin(), 0);
    }
    else if(size2 > size1){
        int to_pad = size2 - size1;
        number1.insert(number1.begin(), to_pad + 1, 0);
        number2.insert(number2.begin(), 0);
    }
    else{
        number1.insert(number1.begin(), 0);
        number2.insert(number2.begin(), 0);
    }
}

vector<int> operator+(vector<int>& v1, vector<int>& v2)
{
    auto p1 = v1.rbegin();
    auto p2 = v2.rbegin();
    
    int carry = 0;
    int sum = 0;
    
    int range = v1.size();
    
    vector<int> result;
    for (int i = 0; i < range; i++){
        sum = *p1 + *p2 + carry;
        
        if(sum > 9){
            carry = 1;
            sum -= 10;
        }
        else{
            carry = 0;
        }
        
        result.insert(result.begin(), sum);
        p1++;
        p2++;
    }
    
    if (carry) result.insert(result.begin(), carry);
    return result;
    
}
vector<int> operator-(const vector<int>& v1, const vector<int>& v2)
{
    auto p1 = v1.rbegin();
    auto p2 = v2.rbegin();
    
    int borrow = 0;
    int difference = 0;
    
    vector<int> result;
    
    int range = v1.size();
    
    for (int i = 0; i < range; i++){
        int op1 = *p1;
        int op2 = *p2;
        
        if (borrow){
            if(op1 == 0){
                op1 = 9;
                borrow = 1;
            }
            else{
                --op1;
                borrow = 0;
            }
        }
        
        if (*p1 >= *p2){
            difference = op1 - op2;
            borrow = 0;
        }
        else{
            difference = op1 + 10 - op2;
            borrow = 1;
        }
        
        result.insert(result.begin(), difference);
        p1++;
        p2++;
    }
    
    if (borrow){
        while(!borrow){
            if(*p1 == 0){
                result.insert(result.begin(), 9);
                borrow = 1;
            }
            else{
                int num = *p1;
                result.insert(result.begin(), --num);
                borrow = 0;
            }
            
            p1++;
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    if (argc != 3)
        cout << "Usage: ./Karatsuba_multiplication number1 number2" << endl;
    
    else{
        vector<int> number1 = getNumber(argv[1]);
        vector<int> number2 = getNumber(argv[2]);
        
        make_same_size(number1, number2);
        display(number1);
        display(number2);
        
        vector<int> sum = number1 + number2;
        display(sum);
        display(number1);
        display(number2);
        
        vector<int> diff = number1 - number2;
        display(diff);
        cout << endl;
    }
    return 0;
}
