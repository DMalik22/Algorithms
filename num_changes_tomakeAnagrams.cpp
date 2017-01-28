/*
The problem:
Given two strings, a and b, that may or may not be of the same length, 
determine the minimum number of character deletions required to make a and b anagrams.
Any characters can be deleted from either of the strings.

My solution:
O(n) time and space complexity

I realized that the input strings will have always have one constant property: they will be
comprised exclusively of lowercase alphabets. So I made two vectors of length 26 each to count
the number of occurences of each character of each alphabet in both the strings and compared the difference.
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
    vector<int> a_characterCount(26, 0);
    vector<int> b_characterCount(26, 0);
    int diff;
    
    for(char c : a)
        (a_characterCount[c - 'a'])++; 
    
    for(char c : b)
        (b_characterCount[c - 'a'])++;
    
    for(int i = 0; i < 26; i++ )
        diff += abs(a_characterCount[i] - b_characterCount[i]);
    
    return diff;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}


