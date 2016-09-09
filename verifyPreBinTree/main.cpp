#include <iostream>
#include <queue>

using namespace std;
const string POUND_SIGN = "#";

bool validationHelper(queue<string> &nodes);
bool isValidSerialization(string preorder);
queue<string> splitString(string s);

int main() {
  string input = "9,3,4,#,#,1,#,#,2,#,6,#,#";
  //string input = "1,#";
  cout << isValidSerialization(input) << endl;
  return 0;
}

queue<string> splitString(string s) {
  queue<string> stk;

  while (s.find(',') != string::npos) {
    size_t pos = s.find(",");
    stk.push(s.substr(0, pos));
    s = s.substr(pos+1);
  }
  stk.push(s);
  return stk;
}

bool isValidSerialization(string preorder) {
  if (preorder.empty())
    return true;

  queue<string> nodes = splitString(preorder);
  bool isValid = validationHelper(nodes);
  return isValid && nodes.empty();
}

bool validationHelper(queue<string> &nodes) {
  if (nodes.empty()) return false;
  string root = nodes.front();
  nodes.pop();
  if (root.compare(POUND_SIGN) == 0) {
    return true;
  }
  bool isLeftTreeValid = validationHelper(nodes);
  bool isRightTreeValid = validationHelper(nodes);
  return isLeftTreeValid && isRightTreeValid;
}
