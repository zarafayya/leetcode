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
    void sumNode(ListNode* l1, ListNode* l2, int addition) {
        if (l1 && l2) {
            int tmp = l1->val + l2->val + addition;
            l1->val = tmp % 10;
            int newAddition = tmp / 10;
            
            if (newAddition > 0 || l2->next) {
                if (!l1->next) l1->next = new ListNode(0);
                if (!l2->next) l2->next = new ListNode(0);
            }

            sumNode(l1->next, l2->next, newAddition);
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        sumNode(l1, l2, 0);
        return l1;
    }
};