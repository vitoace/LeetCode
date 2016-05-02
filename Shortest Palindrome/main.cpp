#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string shortestPalindrome(string s) {
    if (s.empty()) return "";
    string reverse = string(s.rbegin(), s.rend());
    string p = s + "#" + reverse;
    size_t l = p.size();
    vector<int> next(l, 0);
    for (size_t i = 1; i < l; i++) {
      int j = p[i-1];
      if (j > 0 && p[i] != p[j]) j = p[j-1];
      p[i] = (j + (p[i] == p[j]));
    }
    return reverse.substr(0, s.size() - p[l-1]) + s;
  }


};

int main() {
  Solution s;
  cout << s.shortestPalindrome("abcdaa") << endl;
  return 0;
}
