#include <iostream>

using namespace std;
int num_of_ways(int n){
    if(n <= 0 ) return 0;
    if(n == 1) return 1;
    int count = 0;
    int numWays[3] = {1, 1, 2};
    for(int i = 3; i <= n; i++){
        count = numWays[0] + numWays[1] + numWays[2];
        numWays[0] = numWays[1];
        numWays[1] = numWays[2];
        numWays[2] = count;
    }
    return count;
}

int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        cout <<  num_of_ways(n) << endl;
    }
    
    return 0;
}


