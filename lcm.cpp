#include <iostream>
#include <cmath>
unsigned long long Euclid(unsigned long long a,unsigned long long b){
    if (b == 0) return a;
    else return Euclid(b, a % b);
}

unsigned long long lcm(unsigned long long a, unsigned long long b){
    unsigned long long c = Euclid(a,b);
    //std::cout << a*b << "\n" << Euclid(a,b) << std::endl;
    return ((std::floor(a/c))*b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
