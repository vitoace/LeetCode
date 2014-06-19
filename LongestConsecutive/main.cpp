#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int> &num);
int main() {
  vector<int> test;
  test.push_back(-1);
  test.push_back(0);
  test.push_back(1);
  cout << longestConsecutive(test) << endl;

  return 0;
}

int longestConsecutive(vector<int> &num) {
  unordered_map<int, int> map;
  int max = 0;
  for (int i = 0; i < num.size(); i++)
    map[num[i]] = 1;
        
  for (int i = 0; i < num.size(); i++) {
    int temp = 0;
    int val = num[i];
    if (map[val] == 1) {
      temp++;
      map[val] = 0;
    }
    else {
      continue;
    }
            
    int lval = val-1;
    while (map[lval] == 1) {
      map[lval] = 0;
      temp++;
      lval--;
    }
            
    int rval = val+1;
    while (map[rval] == 1) {
      map[rval] = 0;
      temp++;
      rval++;
    }
    max = (max < temp) ? temp : max;
  }
        
  return max;
}
