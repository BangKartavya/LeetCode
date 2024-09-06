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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp->next = head;

        set<int> s(begin(nums),end(nums));
        
        ListNode* ans = new ListNode(0);
        ListNode* temp2 = ans;
        
        while(temp->next) {
            if(s.count(temp->next->val)) {
                temp->next = temp->next->next;
            }
            else {
                temp2->next = temp->next;
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        return ans->next;
        
    }
};