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
        vector<int> preorder;
        vector<int> postorder;
        unordered_map<int, int> mp;

        TreeNode* buildTree(int i1, int i2, int j1) {
            if(i1 > i2) return nullptr;

            TreeNode* root = new TreeNode(preorder[i1]);

            if(i1 != i2) {
                int leftVal = preorder[i1 + 1];
                int mid = mp[leftVal];
                int leftSiz = mid - j1 + 1;

                root->left = buildTree(i1 + 1, i1 + leftSiz, j1);
                root->right = buildTree(i1 + leftSiz + 1, i2, mid + 1);
            }

            return root;
        }
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n = preorder.size();
            this->preorder = preorder;
            this->postorder = postorder;

            for(int i = 0; i < n; i++) {
                mp[postorder[i]] = i;
            }

            return buildTree(0, n - 1, 0);
        }
};