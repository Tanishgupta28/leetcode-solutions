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
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        while(!q.empty()){
            int count = q.size();
            vector<int>temp;
            for(int i  = 0 ; i<count ; i++){
                TreeNode* curr = q.front();
                temp.push_back(curr->val);
                TreeNode* left = curr->left;
                TreeNode* right = curr->right;
                q.pop();
                if(left!=NULL)q.push(left);
                if(right!=NULL) q.push(right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};