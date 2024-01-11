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
    
    int differ = 0;
    
    void diff(TreeNode* root,int minV,int maxV) {
        if(root==nullptr) return;
        
        differ = max(differ,max(abs(root->val-minV),abs(root->val-maxV)));
        minV = min(minV,root->val);
        maxV = max(maxV,root->val);
        
        diff(root->left,minV,maxV);
        diff(root->right,minV,maxV);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(root==nullptr) return 0;
        
        int min = root->val;
        int max = root->val;
        
        diff(root,min,max);
        
        return differ;
    }
};