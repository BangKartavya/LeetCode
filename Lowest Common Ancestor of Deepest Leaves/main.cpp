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
    private:
        int height(TreeNode* root) {
            if(!root) return 0;

            int left = height(root->left);
            int right = height(root->right);

            return 1 + max(left, right);
        }

        TreeNode* findAncestor(TreeNode* root, int depth, int maxDepth) {
            if(depth == maxDepth || !root) return root;

            TreeNode* left = findAncestor(root->left, depth + 1, maxDepth);
            TreeNode* right = findAncestor(root->right, depth + 1, maxDepth);

            if(left && right) return root;

            if(!left) return right;

            return left;
        }

    public:
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            int maxi = height(root);

            return findAncestor(root, 1, maxi);
        }
};