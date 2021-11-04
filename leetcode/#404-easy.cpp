/**
 * 404. Sum of Left Leaves
 * https://leetcode.com/problems/sum-of-left-leaves/
 */

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
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
    
    int dfs(TreeNode* node, bool isLeft){
        if (!node) return 0;
        int ans = 0;
        
        if (isLeft and !node->left and !node->right) ans += node->val;
        
        if (node->left) ans += dfs(node->left, true);
        if (node->right) ans += dfs(node->right, false);
        
        return ans;
    }
};