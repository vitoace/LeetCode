#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void pv(vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << ' ';
  }
  cout << endl;
}

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> res;
  if (nums.size() < 3) return res;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size()-2; i++) {
    int n = i+1, m = nums.size()-1;
    if (i != 0 && nums[i] == nums[i-1]) continue; 
    while (m > n) {
      if (nums[i] + nums[n] + nums[m] == 0) {
	vector<int> temp = {nums[i], nums[n], nums[m]};
	res.push_back(temp);
	int lo = nums[n];
	int hi = nums[m];
	while (nums[n] == lo && n < m) n++;
	while (nums[m] == hi && n < m) m--;
      } else if (nums[i] + nums[n] + nums[m] > 0) {
	m--;
      } else {
	n++;
      }
    }
  }
  return res;
}

int main() {
  vector<int> nums = {0,-4,-1,-4,-2,-3,2};
  vector<vector<int>> res = threeSum(nums);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ' ';
    }
    cout << endl;
  }
}
