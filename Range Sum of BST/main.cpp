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
    void inOrder(TreeNode* root,vector<int>& ans) {
        if(root==nullptr) return;
        
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;
        
        inOrder(root,ans);
        
        sort(ans.begin(),ans.end());
        
        int s = 0;
        
        for(auto i:ans) {
            if(i>=low && i<=high) s+=i;
        }
        return s;
    }
};