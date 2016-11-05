#include <iostream>
int fibonacci_fast(int n);


long long get_fibonacci_huge(long long n, long long m) {
    return ((fibonacci_fast(n%m))%m);
}

int fibonacci_fast(int n) {
    int v[2] = {0, 1};
    if (n == 0) return 0;
    if (n == 1) return 1;
    for (int i = 2; i <= n; ++i){
        int prev_second = v[0];
        int prev_first = v[1];
        v[1] = prev_first + prev_second;
        v[0] = prev_first;
        
    }
    return v[1];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
