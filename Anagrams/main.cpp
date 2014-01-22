#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<string> anagrams(vector<string> &strs);
int main() {
  // insert your code here
  vector<string> strs;
  strs.push_back("cat");
  strs.push_back("dog");
  strs.push_back("atc");
  vector<string> res = anagrams(strs);
  for (int i = 0; i < res.size(); i++)
    cout << resf[i] << " ";
  cout << endl;

  return 0;
}

vector<string> anagrams(vector<string> &strs) {
  vector<string> res;
  if (strs.size() <= 1)
    return res;
  vector<string> myStrs = strs;
  for (int i = 0; i < strs.size(); i++)
    sort(strs[i].begin(), strs[i].end());

  typedef map<string, int> MyMap;
  MyMap myMap;
  set<int> mySet;
  for (int i = 0; i < strs.size(); i++) {
    if (myMap.find(strs[i]) != myMap.end()) {
      mySet.insert(i);
      mySet.insert(myMap[strs[i]]);
    }
    else
      myMap[strs[i]] = i;
  }    

  for (set<int>::iterator it = mySet.begin(); it != mySet.end(); it++)
    res.push_back(myStrs[*it]);

  return res;
}
