#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int evalRPN(vector<string> &tokens);
int main() {
  // insert your code here
  vector<string> tokens;
  tokens.push_back("0");
  tokens.push_back("3");
  tokens.push_back("/");
  cout << evalRPN(tokens) << endl;;
  return 0;
}

int evalRPN(vector<string> &tokens) {
  stack<int> st;
  for (int i = 0; i < tokens.size(); i++) {
    int a, b;
    if (tokens[i] == "+") {
      if (st.size() < 2)
	return 0;
      a = st.top();
      st.pop();
      b = st.top();
      st.pop();
      st.push(a+b);
    }
    else if (tokens[i] == "-") {
      if (st.size() < 2)
	return 0;
      a = st.top();
      st.pop();
      b = st.top();
      st.pop();
      st.push(b-a);
    }
    else if (tokens[i] == "*") {
      if (st.size() < 2)
	return 0;
      a = st.top();
      st.pop();
      b = st.top();
      st.pop();
      st.push(a*b);
    }
    else if (tokens[i] == "/") {
      if (st.size() < 2)
	return 0;
      a = st.top();
      st.pop();
      b = st.top();
      st.pop();
      st.push(b/a);
    }
    else
      st.push(atoi(tokens[i].c_str()));
  }
  if (st.size() != 1)
    return 0;
  return st.top();
}
