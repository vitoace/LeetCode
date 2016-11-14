#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums);
int main() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(4);
  nums.push_back(4);
  cout << minSubArrayLen(4, nums) << endl;
  return 0;
}

int minSubArrayLen(int s, vector<int>& nums) {
  if (nums.size() == 0) return 0;
  int minLen = INT_MAX; int start = -1, end = -1;
  int sum = 0;
  cout << "end: " << end << " nums.size: " << nums.size() << endl;
  while (end < (int)nums.size()) {
    cout << "hello" << endl;
    if (sum < s) {
      end++;
      sum += nums[end];
    } else {
      minLen = min(minLen, end-start);
      start++;
      sum -= nums[start];
    }
  }
  if (minLen == INT_MAX) minLen = 0;
  return minLen;
}
