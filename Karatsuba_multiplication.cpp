//
//  compilation command -> g++ Karatsuba_multiplication.cpp -o Karatsuba_multiplication
//
//  Algorithms
//
//  Stanford's Algorithms specialization on Coursera
//  Course 1 Week 1 Programming Assignment
//
//  Implementation as understood from: https://courses.csail.mit.edu/6.006/spring11/exams/notes3-karatsuba
//  Additional references: http://www.cplusplus.com/reference/string/ and https://en.wikipedia.org/wiki/Karatsuba_algorithm#Pseudocode
//  function string add() -> http://stackoverflow.com/questions/14576411/adding-strings-of-integers
//
//
//  Created by Deetpanshu Malik on 10/15/16.
//  Copyright © 2016 Deetpanshu Malik. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string Karatsuba_multiplication(string num1, string num2);
string times_power_of_ten(string s, int n);
string add(string str1, string str2);//this funtion has been obtained from stackoverflow

string times_power_of_ten(string s, int n){
    for (int i = 0; i < n; i++)
        s += "0";
    return s;
}

string Karatsuba_multiplication(string num1, string num2){
    if ((num1.size() == 1) && (num2.size() == 1)) return their product
    
    //initializing these variables here to avoid redundant size() calls
    int num1_size = num1.size();
    int num2_size = num2.size();
    
    int size = max(num1_size, num2_size);
    int mid_pt = size / 2;
    
    //making the sizes of the strings equal by padding 0's on the shorter one
    if (size > num1.size()) num1 = string(size - num1_size, '0') + num1;
    if (size > num2.size()) num2 = string(size - num2_size, '0') + num2;
    
    //splitting the numbers
    string high1 = num1.substr(0, mid_pt);
    string low1 = num1.substr(mid_pt);
    string high2 = num2.substr(0, mid_pt);
    string low2 = num2.substr(mid_pt);
    
    string z0 = Karatsuba_multiplication(low1, low2);
    string z1 = Karatsuba_multiplication((low1+high1),(low2+high2));
    string z2 = Karatsuba_multiplication(high1,high2);
    
    //num1*num2 = a*10^size + e*10^mid_pt + d
    //let a*10^size be uno, e*10^mid_pt dos and d tres
    
    string uno = times_power_of_ten(z2, size);
    string tres = z0;
    
    return "";
    
    
}

//this funtion has been obtained from stackoverflow
string add(string str1, string str2){
    int n = max(str1.size(), str2.size());
    if (n > str1.size())
        str1 = string(n-str1.size(), '0') + str1;
    if (n > str2.size())
        str2 = string(n-str2.size(), '0') + str2;
    
    // Final product string, sum of two original strings.
    // The sum of two integers has at most one digit more, for more inputs make
    // below reverse_iterator a back_insert_iterator, then reverse the result
    // and skip the removal of the padding.
    string final(n+1, '0');
    
    // The carry
    char carry = 0;
    
    // Iterators
    string::const_reverse_iterator s1 = str1.rbegin(), e = str1.rend(),
    s2 = str2.rbegin();
    string::reverse_iterator f = final.rbegin();
    
    // Conversion
    for (; s1 != e; ++s1, ++s2, ++f)
    {
        // Bracketing to avoid overflow
        char tmp = (*s1-'0')+(*s2-'0') + carry;
        if (tmp > 9)
        {
            carry = 1;
            tmp -= 10;
        }
        else
        {
            carry = 0;
        }
        *f = tmp + '0';
    }
    final[0] = carry + '0';
    
    // Remove leading zeros from result
    n = final.find_first_not_of("0");
    if (n != string::npos)
    {
        final = final.substr(n);
    }
    
    return final;
}


int main(int argc, const char * argv[]) {
    if (argc != 3)
        cout << "Usage: ./Karatsuba_multiplication number1 number2" << endl;
    
    else{
        string number1 = argv[1];
        string number2 = argv[2];
        Karatsuba_multiplication(number1, number2);
        //cout << KaratsubaMultiplication(number1, number2) << endl;
        
    }
    return 0;
}
