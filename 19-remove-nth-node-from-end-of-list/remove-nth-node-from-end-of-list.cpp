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
        ListNode* prev = head;
        ListNode* curr = head;
        if(curr->next == NULL && n ==1) return NULL;
        while(n-- && curr!=NULL){
            curr = curr->next;
        }
        if(curr==NULL){
            head = head->next;
            return head;
        }
        while(curr->next!=NULL){
            prev = prev->next;
            curr = curr->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};