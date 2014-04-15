#include <iostream>
#include <unordered_map>

using namespace std;

bool isScramble(string s1, string s2);
bool potentialScrambleTree(string s1, string s2);
int main() {

  string s1 = "hobobyrqd";
  string s2 = "hbyorqdbo";

  if (isScramble(s1, s2))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  return 0;
}

bool isScramble(string s1, string s2) {
  cout << s1 << ' ' << s2 << endl;
  if (s1 == "" || s2 == "" || s1 == s2) 
    return true;
            
  if (!potentialScrambleTree(s1, s2)) {
    return false;
  }

  for (int i = 1; i < s1.length(); i++) {
    string s1_left   = s1.substr(0, i);
    string s1_right  = s1.substr(i);
    string s2_left   = s2.substr(0, i);
    string s2_right  = s2.substr(i);
    string s21_left  = s2.substr(0, s2.size()-i);
    string s21_right  = s2.substr(s2.size()-i);
    
    if (isScramble(s1_left, s2_left) && isScramble(s1_right, s2_right))
      return true;
    if (isScramble(s1_left, s21_right) && isScramble(s1_right, s21_left))
      return true;
  }
  return false;
}

bool potentialScrambleTree(string s1, string s2) {
  unordered_map<char, int> map;
  for (int i = 0; i < s1.size(); i++) {
    if (map.find(s1[i]) != map.end())
      map[s1[i]]++;
    else
      map[s1[i]] = 1;
    if (map.find(s2[i]) != map.end())
      map[s2[i]]--;
    else
      map[s2[i]] = -1;
  }
  for (unordered_map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
    if (it->second != 0)
      return false;
  }
  return true;
}
