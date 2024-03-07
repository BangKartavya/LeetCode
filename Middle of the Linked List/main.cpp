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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp1 = head;
        int n = 0;

        while(temp1!=nullptr) {
            n++;
            temp1=temp1->next;
        }

        int mid = n/2;

        int cnt = 0;

        ListNode* temp2 = head;

        while(cnt!=mid) {
            cnt++;
            temp2=temp2->next;
        }
        return temp2;
    }
};