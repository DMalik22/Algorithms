#include <iostream>

//returns the least number of coins of denominations 10, 5 and 1 are needed to get change for an amount m

int get_change(int m) {
    int n = 0;
    n = m / 10;
    m %= 10;
    n += m / 5;
    m %= 5;
    n += m;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
