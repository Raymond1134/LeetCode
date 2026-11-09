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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        queue<pair<TreeNode*, int>> nodeQueue;
        vector<vector<int>> result;
        nodeQueue.emplace(root, 0);

        while (nodeQueue.size() > 0) {
            pair<TreeNode*, int> current = nodeQueue.front();
            nodeQueue.pop();
            if (current.first->left) nodeQueue.emplace(current.first->left, current.second + 1);
            if (current.first->right) nodeQueue.emplace(current.first->right, current.second + 1);

            if (current.second == result.size()) result.emplace_back(1, current.first->val);
            else result[current.second].emplace_back(current.first->val);
        }

        return result;
    }
};
