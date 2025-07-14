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
    int getDecimalValue(ListNode* head) {
        string s;

        ListNode* temp = head;

        while(temp) {
            s += to_string(temp->val);
            temp = temp->next;
        }
        int value = 0;

        for(int i = 0;i<s.size();i++) {
            if(s[i] == '1') {
                value += pow(2,s.size()-i-1);
            }
        }

        return value;
    }
};