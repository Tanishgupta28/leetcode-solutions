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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode* prev = NULL;
        TreeNode* curr = root;
        int ans = -1;
        while(curr!=NULL){
            if(curr->left == NULL){
                count++;
                prev = curr;
                curr = curr->right;
                if(count==k) ans = prev->val;
            }
            else{
                TreeNode* pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred = pred->right;
                }
                if(pred->right==NULL){
                    pred->right = curr;
                    curr= curr->left;
                }
                else{
                    pred->right = NULL;
                    count++;
                    prev = curr;
                    curr = curr->right;
                    if(count == k) ans = prev->val;
                }
            }
        }
        return ans;
    }
};