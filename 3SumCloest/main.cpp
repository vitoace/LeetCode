#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());

  int res = nums[0] + nums[1] + nums[2];
  int minDiff = INT_MAX;
  for (int i = 0; i < nums.size()-2; i++) {
    if (i != 0 && nums[i] == nums[i-1]) continue;
    int n = i+1, m = nums.size()-1;
    while (m > n) {
      int lo = nums[n], hi = nums[m];
      int temp = nums[i] + lo + hi;
      if (minDiff > abs(temp - target)) {
	minDiff = abs(temp-target);
	res = temp;
      }
      if (temp - target == 0) return target;
      else if (temp -target < 0) {
	while (lo == nums[n] && n < m) n++;
      } else {
	while (hi == nums[m] && n < m) m--;
      }
    }
  }
  return res;
}

int main() {
  vector<int> test = {-1, 2, 1, -4};
  cout << threeSumClosest(test, 1) << endl;
}
