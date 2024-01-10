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
    void convert(TreeNode* root,int parent,unordered_map<int,unordered_set<int>>& map) {
        if(root==nullptr) return;
        
        if(map.find(root->val)!=map.end()) map[root->val] = unordered_set<int>();
        
        unordered_set<int>& list = map[root->val];
        
        if(parent!=0) list.insert(parent);
        
        if(root->left!=nullptr) list.insert(root->left->val);
        
        if(root->right!=nullptr) list.insert(root->right->val);
        
        convert(root->left,root->val,map);
        convert(root->right,root->val,map);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,unordered_set<int>> map;
        
        convert(root,0,map);
        
        queue<int> q;
        q.push(start);
        
        int minute = 0;
        
        unordered_set<int> visited;
        visited.insert(start);
        
        while(!q.empty()) {
            int levelSize = q.size();
            
            while(levelSize>0) {
                int current = q.front();
                q.pop();
                
                for(auto num: map[current]) {
                    if(visited.find(num)==visited.end()) {
                        visited.insert(num);
                        q.push(num);
                    }
                }
                levelSize--;
            }
            minute++;
        }
        return minute-1;
    }
};