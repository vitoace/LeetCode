#include <iostream>

using namespace std;

bool isMatch(const char *s, const char *p);
bool isMatch_final(const char *s, const char *p);
int main() {
  const char* s = "aadklfjdldlkfj";
  const char* p = "a*j?l";  
  cout << isMatch(s, p) << endl;
  return 0;
}

bool isMatch_final(const char *s, const char *p) {
  const char* ss = s;
  const char* star = NULL;
  while(*s) {
    if ((*s == *p) || (*p == '?')) {
      s++;
      p++;
    }
    else if (*p == '*') {
      star = p++;
      ss = s;
    }
    else if (star) {
      p = star+1;
      s = ++ss;
    }
    return false;
  }
  while (*p == '*')
    p++;
  return !*p;
}

bool isMatch(const char *s, const char *p) {
  while (*s != '\0' && *p != '\0') {
    switch (*p) {
    case '?':
      s++;
      p++;
      break;
    case '*':
      p++;
      if (*p == '\0')
	return true;
      while(*s != '\0') {
	if (*s == *p && isMatch(++s, ++p))
	  return true;
	s++;
      }
      break;
    default:
      if (*s != *p)
	return false;
      else {
	s++;
	p++;
      }
      break;
    }            
  }
  return (*s == *p);
}
