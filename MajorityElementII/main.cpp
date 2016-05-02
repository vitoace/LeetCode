class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int c1 = 0, c2 = 0, n1 = 0, n2 = 0;
    vector<int> res;
    int n = nums.size();
    if (n <= 1) return nums;
        
    for (int i = 0; i < nums.size(); i++) {
      if (n1 == nums[i]) c1++;
      else if (n2 == nums[i]) c2++;
      else if (c1 == 0) { c1 = 1; n1 = nums[i]; }
      else if (c2 == 0) { c2 = 1; n2 = nums[i]; }
      else c1--, c2--;
    }
        
    c1 = 0, c2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == n1) c1++;
      if (nums[i] == n2) c2++;
    }
                
    if (c1 > n/3) res.push_back(n1);
    if (c2 > n/3 && n1 != n2) res.push_back(n2);
    return res;
  }
};
