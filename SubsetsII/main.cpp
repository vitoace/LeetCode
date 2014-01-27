#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > subsetsWithDup(vector<int> &S);
int main() {
  // insert your code here

  return 0;
}
bool compareVec(vector<int> v1, vector<int>v2) {
  if (v1.size() != v2.size())
    return false;
  for (int i = 0; i < v1.size(); i++)
    if (v1[i] != v2[i])
	return false;
  return true;
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
  vector<vector<int> > res;
  if (S.size() == 0)
    return res;
  std::sort(S.begin(), S.end());
  vector<int> temp;
  res.push_back(temp);
  temp.push_back(S[0]);
  res.push_back(temp);
  int count = 1;
  int pre = S[0];
  for (int i = 1; i < S.size(); i++) {
    int s = 0;
    int sz = res.size();
    if (pre == S[i])
      s = sz - count;
    count = 0;
    for (int j = s; j < sz; j++) {
      temp = res[j];
      temp.push_back(S[i]);
      res.push_back(temp);
      count++;
    }
    pre = S[i];
  }
  return res;
}
