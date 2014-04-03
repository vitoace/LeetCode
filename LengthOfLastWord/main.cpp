#include <iostream>

using namespace std;

int lengthOfLastWord(const char *s);
int main() {
  const char* s = "hello world";
  cout << lengthOfLastWord(s) << endl;
  return 0;
}


int lengthOfLastWord(const char *s) {
  int count = 0;
  int last = 0;
  while(*s != '\0') {
    cout << *s;
    if (*s == ' ') {
      if (count != 0)
	last = count;
      count = 0;
      s++;
      continue;
    }
    s++;
    count++;
  }
        
  if (count == 0)
    return last;
  return count;
}
