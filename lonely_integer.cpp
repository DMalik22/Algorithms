#include <iostream>
#include <vector>

using namespace std;

int lonely_integer(vector < int > a) {
    int to_ret = 0;
    for(int i = 0; i < a.size(); i++)
        to_ret ^= a[i];
    return to_ret;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    cout << lonely_integer(a) << endl;
    return 0;
}


