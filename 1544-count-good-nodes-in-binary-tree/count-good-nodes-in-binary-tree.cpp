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
    int helper(TreeNode* root, int curr){
        if(root==NULL)return 0;
        if(root->val>=curr){
            int left = helper(root->left, root->val);
            int right  = helper(root->right, root->val);
            return 1+left+right;
        }
        else{
            int left = helper(root->left, curr);
            int right  = helper(root->right, curr);
            return left+right; 
        }
    }
    int goodNodes(TreeNode* root) {
        int curr = INT_MIN;
        return helper(root, curr);
    }
};