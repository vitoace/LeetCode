#include <iostream>

using namespace std;

string removeDuplicateLetters(string s);
int main() {
  string s = "bcabc";
  cout << removeDuplicateLetters(s) << endl;
  return 0;
}

string removeDuplicateLetters(string s) {
  bool isVisit[26];
  int charCount[26];
  // "0" acts as a place holder, and character less than 'a' would work
  string res("0");
  for (int i = 0; i < 26; i++) {
    isVisit[i] = false;
    charCount[i] = 0;
  }

  // Get char count first

  for (int i = 0; i < s.size(); i++)
    charCount[s[i]-'a']++;

  /* Iterate through input string
     If it's an unseen char, compare it with the chars in result string one by one backward.
     If the res char is greater and the count of the res char is greater than 0,
     pop it out and set the isVisit for the res char to false.
   */
  for (int i = 0; i <s.size(); i++) {
    charCount[s[i]-'a']--;
    if (isVisit[s[i]-'a']) continue;
    while(s[i] < res.back() && charCount[res.back()-'a']) { // will break at pos 0 for sure, because "0" is less than 'a'-'z'
      isVisit[res.back()-'a'] = false;
      res.pop_back();
    }
    res += s[i];
    isVisit[s[i]-'a'] = true;
  }
  return res.substr(1);
}
