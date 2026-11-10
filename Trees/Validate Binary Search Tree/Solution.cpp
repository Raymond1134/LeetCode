/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBSTHelper(TreeNode* root, long long minimum, long long maximum) {
        if (!root) return true;
        if (root->val <= minimum || root->val >= maximum) return false;
        return isValidBSTHelper(root->left, minimum, root->val) && isValidBSTHelper(root->right, root->val, maximum);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
    }
};
