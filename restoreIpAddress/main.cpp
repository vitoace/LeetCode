#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

void printArray(vector<string> arr) {
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << ' ';
  cout << endl;
}

bool isValid(const string& s) {
  return !s.empty()
    && !(s.size() > 1 && s[0] == '0')
    && stol(s) >= 0
    && stol(s) <= 255;
}

string convert(const vector<string>& ans) {
  string temp = "";
  for (int i = 0; i < 3; i++) {
    temp += ans[i] + '.';
  }
  temp += ans[3];
  return temp;
}

void helper(int l, string s, vector<string> ans, vector<string>& res) {
  cout << "ans: ";
  printArray(ans);
  cout << "res: ";
  printArray(res);
  if (l == 3) {
    if (isValid(s)) {
      ans.push_back(s);
      res.push_back(convert(ans));
    }
  } else {
    int len = min(3, (int)s.size());
    for (int i = 1; i <= len; i++) {
      string sub = s.substr(0, i);
      if (isValid(sub)) {
	ans.push_back(sub);
	helper(l+1, s.substr(i, s.size()-1), ans, res);
      } else {
	return;
      }
      ans.pop_back();
    }
  }
}


vector<string> res;
int main() {
  const string s = "010010";
  vector<string> ans;
  helper(0, s, ans, res);

  for (int i = 0; i < res.size(); i++)
    cout << res[i] << ' ';
  cout << endl;
  return 0;
}

