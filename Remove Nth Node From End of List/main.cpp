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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* temp2 = head;
        int len = 0;
        while(temp!=nullptr) {
            len++;
            temp=temp->next;
        }
        if(len==1) return nullptr;
        
        int st = len-n+1;
        
        if(st==1) {
            return head->next;
        }
        
        int cnt = 1;
        
        while(temp2!=nullptr) {

            if(cnt+1==st) {
                temp2->next=temp2->next->next;
            }
            cnt++;           
            temp2 = temp2->next;
        }
        
        return head;
        
    }
};