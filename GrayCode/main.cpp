#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n);
int main() {
  // insert your code here
  vector<int> res = grayCode(3);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << ' ';
  cout << endl;
  return 0;
}

vector<int> grayCode(int n) {
  vector<int> res;
  if (n == 0) {
    res.push_back(0);
    return res;
  }
  res.push_back(0);
  res.push_back(1);
  for (int i = 1; i < n; i++) {
    int size = res.size();
    for (int j = size-1; j >= 0; j--) {
      res.push_back(res[j] + (1<<i));
    }
  }
  return res;
}
