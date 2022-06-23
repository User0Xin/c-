

  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isUnivalTree(TreeNode* root) 
    {
        return check(root, root->val);
    }
    bool check(TreeNode* root, int val)
    {
        if (root == nullptr)//该节点为空前面验证完为真
        {
            return true;
        }
        if (root->val != val)//数值不相等
        {
            return false;
        }
        return check(root->left, val) && check(root->right, val);//递归遍历
    }
};