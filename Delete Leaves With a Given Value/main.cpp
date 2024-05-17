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
    static TreeNode* removeLeafNodes(TreeNode* root, int target, TreeNode* parent=NULL) {
        if (!root) return NULL;

        root->left = removeLeafNodes(root->left, target, root);
        root->right = removeLeafNodes(root->right, target, root);

        if (!root->left && !root->right && root->val==target) {
            if (parent)  delete root; //the root cannot be deleted
            return NULL;
        }

        return root;
    }
};
