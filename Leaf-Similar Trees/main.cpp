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
    void leaf(TreeNode* root,vector<int>& ans) {
        if(root==nullptr) return;
        
        if(root->left==nullptr && root->right == nullptr) {
            ans.push_back(root->val);
            return;
        }
        
        if(root->left!=nullptr) leaf(root->left,ans);
        if(root->right!=nullptr) leaf(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a1;
        vector<int> a2;
        
        leaf(root1,a1);
        leaf(root2,a2);
        
        if(a1==a2) return true;
        return false;
    }
};