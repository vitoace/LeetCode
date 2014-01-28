#include <iostream>

using namespace std;

int divide(int dividend, int divisor);
int main() {
  // insert your code here
  cout << divide(3, 5) << endl;
  return 0;
}

int divide(int dividend, int divisor) {
  long long a = abs(dividend);
  long long b = abs(divisor);
  long long ret = 0;
  while( a >= b) {
    long long c = b;
    for (int i = 0; a >= c, i++; c <<= 1) {
      a -= c;
      ret += 1 << i;
    }
  }
  return ((dividend^divisor)>>31) ? (-ret) : ret;
}
