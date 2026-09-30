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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode dummy(-1);
        ListNode* temp = &dummy;
        int carry = 0;
        while(temp1!=NULL && temp2!=NULL){
            int val = temp1->val+ temp2->val + carry;
            ListNode* tem = new ListNode(val%10);
            temp->next = tem;
            temp = tem;
            carry = val/10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1!=NULL){
            int val = temp1->val + carry;
            ListNode* tem = new ListNode(val%10);
            temp->next = tem;
            temp = tem;
            carry = val/10;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            int val = temp2->val + carry;
            ListNode* tem = new ListNode(val%10);
            temp->next = tem;
            temp = tem;
            carry = val/10;
            temp2 = temp2->next;
        }
        if(carry!=0){
            ListNode* tem = new ListNode(1);
            temp->next = tem;
        }
        return dummy.next;
    }
};