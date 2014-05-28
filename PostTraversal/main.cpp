#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int v) : val(v), left(0), right(0) {}
};

vector<int> postorderTraversal(TreeNode *root);
int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);
  vector<int> res = postorderTraversal(root);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << ' ';
  }
  cout << endl;
}

void pOrderTraversal(TreeNode *root, vector<int>& res);
vector<int> postorderTraversal(TreeNode *root) {
  vector<int> res;
  pOrderTraversal(root, res);
  return res;        
}
    
void pOrderTraversal(TreeNode *root, vector<int>& res) {
  if (root == 0)
    return;
  if (root->left != 0)
    pOrderTraversal(root->left, res);
  if (root->right != 0)
    pOrderTraversal(root->right, res);
  res.push_back(root->val);
}
