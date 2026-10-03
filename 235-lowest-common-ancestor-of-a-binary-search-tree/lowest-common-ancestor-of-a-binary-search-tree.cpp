/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
bool find(TreeNode* root, TreeNode* p){
    if(root==NULL) return false;
    if(root == p) return true;
    return find(root->left, p)|| find(root->right,p);
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p) return p;
        if(root==q) return q;
        bool flag1 = find(root->left, p) && find(root->right,q);
        bool flag2 = find(root->right, p) && find(root->left,q);
        bool flag3 = find(root->right, p) && find(root->right,q);
        bool flag4 = find(root->left, p) && find(root->left,q);
        if(flag1 || flag2) return root;
        else if(flag3){
            return lowestCommonAncestor(root->right, p, q);
        }
        else return lowestCommonAncestor(root->left, p, q);
    }
};