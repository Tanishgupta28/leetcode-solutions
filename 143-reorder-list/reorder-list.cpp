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
ListNode* reverseLink(ListNode* head){
    ListNode* prev = NULL;
    ListNode* nxt = NULL;
    ListNode* curr = head;
    while(curr!=NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        if(fast==NULL || fast->next==NULL)return;
        while(fast!=NULL && fast->next!= NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* head1 = reverseLink(slow);
        ListNode* temp1 = head1 ;
        ListNode* temp = head;
        while(temp->next!=NULL && temp1!=NULL){
            ListNode* nxt = temp->next;
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
            temp->next = nxt;
            temp = nxt;
        }
        if(temp1!=NULL) temp->next = temp1;
    }
};