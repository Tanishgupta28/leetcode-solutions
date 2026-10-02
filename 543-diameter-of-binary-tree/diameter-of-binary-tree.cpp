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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int lefthight = height(root->left);
        int rightheight = height(root->right);
        return 1+max(lefthight, rightheight);
    }
    void helper(TreeNode* root, int &ans){
        if(root==NULL) return;
        int left = height(root->left);
        int right = height(root->right);
        int dia = left+right;
        ans = max(dia, ans);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};