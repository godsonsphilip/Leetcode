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
    bool isTrue(TreeNode* p, TreeNode* q){
        if(p==NULL && q == NULL) return true;
        if(p==NULL || q == NULL || p->val!=q->val) return false;

        bool a = isTrue(p->left, q->right);
        bool b = isTrue(p->right, q->left);
        return (a && b);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        bool w = isTrue(root->left, root->right);
        return w;
    }
};