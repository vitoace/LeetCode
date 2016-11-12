#include <iostream>
#include <vector>

using namespace std;

int maxCoins(vector<int>& nums);
int main() {
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(5);
  nums.push_back(8);
  cout << maxCoins(nums) << endl;
  return 0;
}

void printVector(const vector<vector<int> > &nums);

int maxCoins(vector<int>& nums) {
  const int n = nums.size();
  nums.insert(nums.begin(), 1);
  nums.push_back(1);
  vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
  int len = 1;
  for (; len <= n; len++) {
    int l = 1, r = l+len-1;
    while(r <= n) {
      for (int i = l; i <= r; i++)
	dp[l][r] = max(dp[l][r], nums[l-1]*nums[r+1]*nums[i]+dp[l][i-1]+dp[i+1][r]);
      
      l++;
      r++;
    }
    printVector(dp);
  }
  return dp[1][n];
}

void printVector(const vector<vector<int> > &nums) {
  for(int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < nums[i].size(); j++) {
      cout << nums[i][j] << '\t';
    }
    cout << endl;
  }
  cout << endl;
}
