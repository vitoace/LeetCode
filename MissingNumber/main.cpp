#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums);
int main() {
  vector<int> nums{0, 1, 3};
  cout << missingNumber(nums);
}

int missingNumber(vector<int>& nums) {
  int size = nums.size();
  if (size == 0) return 0;
  int total = size * (size + 1) / 2;
  int fake_total = 0;
  for (int i = 0; i < size; i++)
    fake_total += nums[i];
  return total - fake_total;
}
