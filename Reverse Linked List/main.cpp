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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || head->next==nullptr) return head;
        
        vector<int> v;
        
        while(head!=nullptr) {
            v.push_back(head->val);
            head= head->next;
        }
        
        reverse(v.begin(),v.end());
        
        ListNode* h = new ListNode(v[0]);
        ListNode* t = h;
        
        for(int i =1;i<v.size();i++) {
            t->next = new ListNode(v[i]);
            t = t->next;
        }
        return h;
    }
};