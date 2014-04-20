#include <iostream>

using namespace std;

void reverseWords_recursion(string &s);
void reverseWords(string &s);
int main() {
  string s = "the sky is blue";
  reverseWords_recursion(s);
  cout << s << endl;
  return 0;
}

void reverseWords(string &s) {
  int l = s.size()-1;
  int start = 0;
  while (l >= 0) {
    int size = s.size();
    if (s[size-1] == ' ') {
      l--;
      s = s.substr(0, size-1);
      continue;
    }
    
    string temp = ""; 
    int count = 0;
    while(s[size-1] != ' ' && l >= 0) {
      temp = s[size-1] + temp;
      size--;
      l--;
      count++;
    }
    temp += ' ';
    count++;
    string rhs = s.substr(start, size-start);
    string lhs = s.substr(0, start);
    cout << s << endl;
    cout << lhs << '|' << temp << '|' << rhs << endl;
    start += count;
    s = lhs + temp + rhs;
  }
  s = s.substr(0, s.size()-1);
  return;
}

void reverseWords_recursion(string &s) {
  if (s.empty())
    return;
  
  while (s[s.size()-1] == ' ')
    s = s.substr(0, s.size()-1);

  int i = s.size();
  string temp;
  while(s[i-1] != ' ') {
    temp = s[i-1]+temp;
    i--;
  }
  
  string rhs = s.substr(0, s.size()-temp.size());
  reverseWords_recursion(rhs);
  s = temp + ' ' + rhs;
}


