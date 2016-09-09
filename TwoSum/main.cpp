#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum2(vector<int>& nums, int target);
vector<int> twoSum(vector<int>& nums, int target);
int main() {
  vector<int> nums{3,2,4};
  int target = 6;
  vector<int> res = twoSum2(nums, target);
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

vector<int> twoSum2(vector<int>& nums, int target) {
  map<int, int> temp;
  vector<int> res;
  for (int i = 0; i < nums.size(); ++i)
    temp[nums[i]] = i;
  for (int i = 0; i < nums.size(); ++i)
    
    if (temp.find(target - nums[i]) != temp.end()
	&& temp[target-nums[i]] != i) {
      res.push_back(i);
      res.push_back(temp[target-nums[i]]);
      return res;
    }
  return res;
}

