#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);
int main() {
  vector<int> nums{2, 7, 10, 11};
  int target = 9;
  vector<int> res = twoSum(nums, target);
  for (int i = 0; i < res.size(); ++i)
    cout << res[i] << ' ';
  cout << endl;
  return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i+1; j < nums.size(); ++j) {
      if (nums[i]+nums[j] == target) {
	vector<int> res{i, j};
	return res;
      }
    }      
  }
}
