/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* nxt = NULL;
        Node* temp = head;
        Node dummy(-1);
        Node* temp1 = &dummy;
        unordered_map<Node*,Node*>mp;
        while(temp!=NULL){
            // nxt = temp->next;
            Node* tem = new Node(temp->val);
            temp1->next = tem;
            temp1 = temp1->next;
            mp[temp] = temp1;
            temp1->random = temp;
            temp = temp->next;
            // temp->next = temp1;
            // temp = nxt;
        }
        temp1 = dummy.next;
        while(temp1!=NULL){
            if(temp1->random->random!=NULL){
                temp1->random = mp[temp1->random->random];
            }
            else temp1->random = NULL;

            temp1 = temp1->next;
        }
        return dummy.next;
    }
};