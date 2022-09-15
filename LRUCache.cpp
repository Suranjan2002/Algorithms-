class LRUCache {
public:
    class node{
        public:
        int k;
        int val;
        node* next;
        node* prev;
        node(int key,int value)
        {
            k = key;
            val = value;
        }
    };
    int c;
    node* head = new node(0,0);
    node* tail = new node(0,0);
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        c = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node* temp)
    {
        node*f =head->next;
        temp->next =f;
        head->next =temp;
        temp->prev=head;
        f->prev = temp;
    }
    void deletenode(node* t)
    {
        node* f= t->next;
        node* p = t->prev;
        p->next =f;
        f->prev = p;
        
    }
    int get(int key) {
       if(mp.find(key)!=mp.end())
       {
           node* temp = mp[key];
           int ans = temp->val;
           mp.erase(key);
           deletenode(temp);
           addnode(temp);
           mp[key]=head->next;
           return ans;
       }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            node* temp = mp[key];
            mp.erase(key);
            deletenode(temp);
        }
        if(mp.size()==c)
        {
            mp.erase(tail->prev->k);
            deletenode(tail->prev);
            
        }
        addnode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
