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
        if(root==NULL) return {};
        vector<vector<int>> result;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){

            vector<int> list;
            int l = q.size();
            for(int i = 0; i<l; i++){
                auto p = q.front();
                q.pop();
                if(p){
                    list.push_back(p->val);
                    q.push(p->left);
                    q.push(p->right);
                }
            }
            if(!list.empty())
            result.push_back(list);
        }
        return result;
    }
};