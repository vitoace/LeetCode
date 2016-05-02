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
      int j = next[i-1];
      if (j > 0 && next[i] != next[j]) j = next[j-1];
      next[i] = (j + (next[i] == next[j]));
    }
    printVector(next);
    return reverse.substr(0, s.size() - next[l-1]) + s;
  }

  void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << ' ';
    }
    cout << endl;
  }

};

int main() {
  Solution s;
  cout << s.shortestPalindrome("abcdaa") << endl;
  return 0;
}
