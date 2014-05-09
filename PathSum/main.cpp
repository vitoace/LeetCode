#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum);
int main() {
  return 0;
}

bool hasPathSum(TreeNode *root, int sum) {
  bool lt = false, rt = false;
  while (root != 0) {
    if (root->left == 0 && root->right == 0)
      return (root->val - sum == 0);
    if (root->left != 0) {
      lt = hasPathSum(root->left, sum-root->val);
    }
    if (root->right != 0) {
      rt = hasPathSum(root->right, sum-root->val);      
    }
    return (lt || rt);
  }

  return (sum == 0);
}
