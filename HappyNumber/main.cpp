#include <iostream>
#include <map>

using namespace std;
bool isHappy(int n);
  
int main() {
  cout << isHappy(19) << endl;
  return 0;
}

bool isHappy(int n) {
  int sqr = 0;
  map<int, int> m;
  while (sqr != 1) {
    sqr = 0;
    while(n != 0) {
      sqr += (n % 10)*(n % 10);
      n /= 10;
    }
    cout << "sqr: " << sqr << endl;
    if (m.find(sqr) != m.end()) return false;
    else m[sqr] = sqr;
    n = sqr;
  }
  return true;
}
