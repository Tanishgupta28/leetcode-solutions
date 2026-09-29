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
        stack<ListNode*>st; 
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow;
        while(temp!=NULL){
            st.push(temp);
            temp = temp->next;
        }
        ListNode* temp1 = head;
        while(temp1!=slow){
            ListNode* temp2 = st.top();
            st.pop();
            ListNode* nxt;
            nxt = temp1->next;
            temp1->next = temp2;
            temp1 = temp1->next;
            temp1->next = nxt;
            temp1 = nxt;
        }
        temp1->next = NULL;
    }
};