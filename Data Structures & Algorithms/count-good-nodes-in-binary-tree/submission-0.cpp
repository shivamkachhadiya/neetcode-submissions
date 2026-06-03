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
    int count = 0;
    void solve(TreeNode* root, int rootData) {
        if (root == NULL) return;
        int currData = root->val;
        if (currData >= rootData) {
            count++;
        }
        solve(root->left, rootData);
        solve(root->right, rootData);
    }

    int goodNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int rootData = root->val;
        solve(root, rootData);

        return count;
    }
};
