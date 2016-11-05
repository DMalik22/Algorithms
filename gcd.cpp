#include <iostream>

int Euclid(int a, int b){
    if (b == 0) return a;
    else return Euclid(b, a % b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << Euclid(a, b) << std::endl;
  return 0;
}
