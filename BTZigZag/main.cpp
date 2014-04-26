#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root);
int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  vector<vector<int> > res = zigzagLevelOrder(root);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << ' ';
    cout << endl;
  }
  return 0;
}

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
  vector<vector<int> > res;
  if (root == 0)
    return res;
  stack<int> lvl;
  stack<TreeNode*> q;
  q.push(root);
  lvl.push(0);
  while(!q.empty() && !lvl.empty()) {
    TreeNode* cur = q.top();
    int cur_lvl = lvl.top();
    q.pop();
    lvl.pop();
    if (cur_lvl >= res.size()) {
      vector<int> temp;
      res.push_back(temp);
    }
    res[cur_lvl].push_back(cur->val);
    if (cur->left != 0) {
      q.push(cur->left);
      lvl.push(cur_lvl+1);
    }   
    if (cur->right != 0) {
      q.push(cur->right);
      lvl.push(cur_lvl+1);
    }
  }

  for (int i = 0; i < res.size(); i+=2) {
    std::reverse(res[i].begin(), res[i].end());
  }
  return res;
}
