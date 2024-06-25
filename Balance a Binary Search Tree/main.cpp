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
        if(!root) return;

        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    TreeNode* build(vector<int>& elem,int s,int e) {
        if(s>e) return NULL;

        int mid = s + (e-s)/2;
        TreeNode* node = new TreeNode(elem[mid]);
        node->left = build(elem,s,mid-1);
        node->right = build(elem,mid+1,e);

        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inOrder(root,ans);
        return build(ans,0,ans.size()-1);
    }
};