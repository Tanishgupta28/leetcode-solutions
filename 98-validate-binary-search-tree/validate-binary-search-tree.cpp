/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        bool flag = true;
        while (root != NULL) {
            if (root->left == NULL) {
                if (prev != NULL && prev->val >= root->val) {
                    flag = false;
                }
                prev = root;
                root = root->right;
            } else {
                TreeNode* pred = root->left;
                while (pred->right != NULL && pred->right != root) {
                    pred = pred->right;
                }
                if (pred->right == NULL) {
                    pred->right = root;
                    root = root->left;
                } else {
                    pred->right = NULL;
                    if (prev != NULL && prev->val >= root->val) {
                        flag = false;
                    }
                    prev = root;
                    root = root->right;
                }
            }
        }
        return flag;
    }
};