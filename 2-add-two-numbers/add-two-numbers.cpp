class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry) {
            int val = carry;

            if(l1 != NULL) {
                val += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL) {
                val += l2->val;
                l2 = l2->next;
            }

            temp->next = new ListNode(val % 10);
            temp = temp->next;

            carry = val / 10;
        }

        return dummy.next;
    }
};

// more optimaly written 