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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* curr2 = slow->next;
        slow->next = NULL;
        // reversal 
        ListNode* prev = NULL;
        ListNode* Next2 = NULL;
        while(curr2!=NULL){
            Next2 = curr2->next;
            curr2->next = prev;
            prev = curr2;
            curr2 = Next2;
        }
        Next2 = NULL;
        curr2 = prev;
        ListNode* curr1 = head;
        ListNode* Next1 = NULL;
        while(curr2!=NULL){
            Next2 = curr2->next;
            Next1 = curr1->next;
            curr2->next = curr1->next;
            curr1->next = curr2;
            curr2 = Next2;
            curr1 = Next1;
        }
    }
};