/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode* head,ListNode* cur, TreeNode* root) {
        if(!cur) return true;
        if(!root) return false;

        if(root->val == cur->val) cur = cur->next;
        else if(head->val == root->val) {
            head = head->next;
        }
        else cur = head;
        return dfs(head,cur,root->left) || dfs(head,cur,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head,head,root);
    }
};