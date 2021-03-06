#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs);
int main() {
  vector<string> strs;
  strs.push_back("HelloWorld");
  strs.push_back("HelloPig");
  strs.push_back("Helfldkj");
  cout << longestCommonPrefix(strs) << endl;
  return 0;
}

string longestCommonPrefix(vector<string> &strs) {
  if (strs.size() == 0)
    return "";
  string prefix = strs[0];
  for (int i = 1; i < strs.size() && prefix.size() != 0; i++) {
    int s = min(prefix.size(), strs[i].size());
    string newPrefix = "";
    for (int j = 0; j < s; j++) {
      if (prefix[j] == strs[i][j]) {
	newPrefix += prefix[j];
      }
      else
	break;
    }
    prefix = newPrefix;
  }
  return prefix;
}
