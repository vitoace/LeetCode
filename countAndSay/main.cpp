#include <iostream>
#include <vector>

using namespace std;

string countAndSay(int n);
int main() {
  // insert your code here
  int n = 5;
  
  cout << countAndSay(n) << endl;
  return 0;
}

string countAndSay(int n) {
  if (n <= 1)
    return std::to_string(n);
  
  string res = "1";
  for (int i = 1; i < n; i++) {
    char curChar = res[0];
    int count = 1;
    string temp = "";
    for (int j = 1; j < res.length(); j++) {
      if (curChar != res[j]) {
	temp += std::to_string(count);
	temp += curChar;
	count = 1;
	curChar = res[j];
      }
      else 
	count++;
    }
    if (count != 0) {
      temp += std::to_string(count);
      temp += curChar;
    }
    res = temp;
  }
  return res;
}
