#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > permute(vector<int> &num);
int main() {
  // insert your code here
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  vector<vector<int> > res = permute(nums);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << ' ';
    cout << endl;
  }
  return 0;
}

void permuteHelper(vector<vector<int> >& res, vector<int> nums, vector<int> temp, vector<bool> isVisted) {
  if (temp.size() == nums.size())
    res.push_back(temp);
  for (int i = 0; i < nums.size(); i++) {
    if (!isVisted[i]) {
      temp.push_back(nums[i]);
      isVisted[i] = true;
      permuteHelper(res, nums, temp, isVisted);
      temp.pop_back();
      isVisted[i] = false;
    }
  }
  return;
}

vector<vector<int> > permute(vector<int> &nums) {
  vector<vector<int> > res;
  vector<bool> isVisted;
  vector<int> temp;
  for(int i = 0; i < nums.size(); i++) {
    isVisted.push_back(false);
  }
  permuteHelper(res, nums, temp, isVisted);
  return res;
}
