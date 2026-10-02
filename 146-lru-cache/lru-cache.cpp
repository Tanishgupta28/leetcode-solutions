class Node{
    public:
        Node* next;
        Node* prev;
        int val;
        int key; // we are putting key so that when its capacity is full we can remove it from hashmap
    Node(int val, int key){
        next = NULL;
        prev = NULL;
        this->val =val;
        this->key = key;
    }
};
class LRUCache {
public:
int capacity; 
Node * dummy = new Node(-1,-1);
Node* temp = dummy;
unordered_map<int, Node*>mp;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    void del(Node* newtemp){
        Node* pre = newtemp->prev;
        Node* nxt = newtemp->next;
        if(nxt == NULL){
            pre->next = NULL;
            temp = pre;
        }
        else{
            nxt->prev = pre;
            pre->next = nxt;
        }
        newtemp->prev = NULL;
        newtemp->next = NULL;
    }
    void add(Node* newtemp){
        temp->next = newtemp;
        newtemp->prev = temp;
        temp = newtemp;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node*curr = mp[key];
            del(curr);
            add(curr);
            return curr->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node*curr = mp[key];
            curr->val = value;
            del(curr);
            add(curr);
        }
        else{
            if(mp.size()<capacity){
                Node* curr = new Node(value, key);
                mp[key] = curr;
                add(curr);
            }
            else{
                Node* curr1 = dummy->next;
                int k = curr1->key;
                mp.erase(k);
                del(curr1);
                Node*curr2 = new Node(value, key);
                mp[key] = curr2;
                add(curr2);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */