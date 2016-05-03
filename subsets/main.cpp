#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    vector<int> tmp;
    res.push_back(tmp);

    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      int n = res.size();
      int lastSize = 0;
      
      // Add if check to avoid duplication
      // if (i != 0 && nums[i] == nums[i-1])
      // 	lastSize = n - count;
      count = 0;
      cout << "last size: " << lastSize << endl;
      cout << "count: " << count << endl;
      cout << "n: " << n << endl;
      for (int j = lastSize; j < n; j++) {
	tmp = res[j];
	tmp.push_back(nums[i]);
	res.push_back(tmp);
	count++;
      }
    }
    return res;
  }
  void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
      cout << v[i] << ' ';
    cout << endl;
  }
};

int main() {
  vector<int> input;
  input.push_back(1);
  input.push_back(1);
  // input.push_back(2);
  Solution s;
  vector<vector<int> > res = s.subsetsWithDup(input);
  for (int i = 0; i < res.size(); i++) {
    s.printVector(res[i]);
  }
  return 0;
}
