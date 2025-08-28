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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }

    int solve(TreeNode* root, int &maxi){
        if(root==NULL) return 0;

        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);
        if(left<0) left=0;
        if(right<0) right = 0;
        maxi = max(maxi, left + right + root->val);

        return root->val + max(left, right);
    }
};