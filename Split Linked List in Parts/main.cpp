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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        ListNode* cur = head;

        int len = 0;

        while(cur) {
            len++;
            cur = cur->next;
        }
        cur = head;

        int total = len/k;
        int extra = len%k;

        for(int i =0;i<k && cur;i++) {
            ans[i] = cur;
            int curPart = total + (extra > 0 ? 1 : 0);
            extra--;

            for(int j =1;j<curPart;j++) cur = cur->next;

            ListNode* next = cur->next;
            cur->next = NULL;
            cur = next;
        }
        return ans;
    }
};