class Solution {
public:
typedef pair<int,ListNode*> pip;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pip,vector<pip>,greater<pip>>pq;
        int n = lists.size();
        for(int i = 0 ; i<n ; i++){
            if(lists[i]!=NULL){
                ListNode* curr = lists[i];
                int valu = curr->val;
                pq.push({valu,curr});
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!pq.empty()){
            auto curr = pq.top();
            ListNode* tempo = curr.second;
            pq.pop();
            if(tempo->next!=NULL){
                ListNode* nxt = tempo->next;
                int valu = nxt->val;
                pq.push({valu,nxt});
            }
            temp->next = tempo;
            temp  = temp->next;
        }
        return dummy->next;
    }
};