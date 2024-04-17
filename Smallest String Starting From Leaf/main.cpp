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
    deque<char> t = {'|'};
public:
    void f(TreeNode* node,deque<char>& s) {
        if(!node) return;
        s.push_front(node->val+'a');

        if(!node->left && !node->right) if(s<t) t = s;

        f(node->left,s);
        f(node->right,s);
        s.pop_front();
    }
    string smallestFromLeaf(TreeNode* root) {
        deque<char> s = {};
        f(root,s);
        return string(t.begin(),t.end());
    }
};