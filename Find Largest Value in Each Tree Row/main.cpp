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
        vector<int> largestValues(TreeNode* root) {
            vector<int> ans;
            if(!root) return ans;

            if(!root->left && !root->right) return {root->val};

            queue<pair<TreeNode*, int>> q;
            q.push({root, 0});

            int cur_level = 0;
            int cur_max = INT_MIN;

            while(!q.empty()) {
                pair<TreeNode*, int> top = q.front();
                q.pop();

                if(cur_level == top.second) {
                    cur_max = max(cur_max, top.first->val);
                } else {
                    ans.push_back(cur_max);
                    cur_level = top.second;
                    cur_max = INT_MIN;
                    cur_max = max(cur_max, top.first->val);
                }
                if(top.first->left) q.push({top.first->left, top.second + 1});
                if(top.first->right) q.push({top.first->right, top.second + 1});
            }
            ans.push_back(cur_max);
            return ans;
        }
};