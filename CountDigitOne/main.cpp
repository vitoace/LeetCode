#include <iostream>
#include <cmath>

using namespace std;

int countDigitOne(int n) {
  if (n <= 0) return 0;
  if (n < 10 && n >=1) return 1;
  string ns = to_string(n);
  int len = ns.size();
  int count = 0;
  for (int i = 0; i < len; i++) {
    int left = 0, right = 0;
    if (i > 0) { left = n / pow(10, len-i); }
    if (i < len-1) { right = n % int(pow(10, len-i-1)); }
    int cur = ns[i] - '0';
    cout << left << ' ' << cur << ' ' << right << endl;
    switch(cur) {
    case 0:
      count += left*pow(10, len-i-1);
      break;
    case 1:
      count += left*pow(10, len-i-1) + right + 1;
      break;
    default:
      count += left*pow(10, len-i-1) + pow(10, len-i-1);
      break;
    }
    cout << "count: " << count << endl;
  }
  return count;
}

int main() {
  cout << countDigitOne(13) << endl;

  return 0;
}
