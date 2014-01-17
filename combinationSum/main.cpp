#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > combinationSum(vector<int> &candidates, int target);
int main() {
  // insert your code here
  vector<int> candidates;
  int target = 8;
  candidates.push_back(1);
  candidates.push_back(5);
  candidates.push_back(10);

  vector<vector<int> > res = combinationSum(candidates, target);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j <res[i].size(); j++)
      cout << res[i][j] << ' '; 
    cout << endl;
  }
  return 0;
}

void combinationSumHelper(const vector<int>& candidates, int pos, int target);
vector<vector<int> > res;
vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  combinationSumHelper(candidates, 0, target);
  return res;
}
    
vector<int> answer;
void combinationSumHelper(const vector<int>& candidates, int pos, int target) {
  if (target < 0)
    return;
  if (target == 0) {
    res.push_back(answer);
    return;
  }
            
  for (int i = pos; i < candidates.size(); i++) {
    answer.push_back(candidates[i]);
    combinationSumHelper(candidates, i, target-candidates[i]);
    answer.pop_back();
  }
}
