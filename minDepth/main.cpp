#include<iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    int m = -1;
    findMinDepth(root, 0, m);
    return m+1;
  }
    
  void findMinDepth(TreeNode* root, int depth, int& m) {
    if (root->left == NULL && root->right == NULL) {
      if (m < 0) m = depth;
      else m = min(depth, m);
    }
    if (root->left != NULL)  findMinDepth(root->left, depth+1, m);
    if (root->right != NULL) findMinDepth(root->right, depth+1, m);
  }
};

int main() {
  Solution s;
  
  TreeNode* root = new TreeNode(0);
  //root->left = new TreeNode(1);
  cout << s.minDepth(root) << endl;
  return 0;
}
