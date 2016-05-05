#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int longestValidParentheses_dp(string s) {
    if (s.length() <= 1) return 0;
    int m = 0;
    vector<int> dp(s.length(), 0);
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == ')') {
	if (s[i-1] == ')') { // closing
	  int j = i-1-dp[i-1];
	  if (j >= 0) {
	    if (s[j] == '(') {
	      dp[i] = dp[i-1]+2;
	      if (j-1 >= 1) dp[i] += dp[j-1];
	    }
	    else dp[i] = 0;
	  }
	} else { // opening
	  int j = i - 2;
	  if (j >= 0) {
	    dp[i] = 2 + dp[j];
	  } else dp[i] = 2;
	}
      }
      m = max(m, dp[i]);
    }
    for (int i = 0; i < dp.size(); i++)
      cout << dp[i] << ' ';
    cout << endl;
    return m;
  }

  int longestValidParentheses_stack(string s) {
    vector<pair<char, int> > stack;
    int start = 0, m = 0, curLen = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') { // opening
        stack.push_back(make_pair(s[i], i));
      } else { // closing
	if (stack.empty() || stack.back().first == ')') {
          stack.push_back(make_pair(s[i], i));
        } else {
          stack.pop_back();
	  if (stack.empty()) curLen = i+ 1;
	  else curLen =i - stack.back().second;
        }
      }
      m = max(m, curLen);
    }
    return m;
  }


};

int main() {
  Solution s;
  string input("()(())");
  cout << input << endl;
  cout << s.longestValidParentheses_dp(input) << endl;
  cout << s.longestValidParentheses_stack(input) << endl;
  return 0;
}
