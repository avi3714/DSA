class LRUCache {
public:
class node{
    public:
    int key;
    int val;
    node* next;
    node* prev;
    node(int _key,int _val)
    {
        key=_key;
        val=_val;
    }
 };
 node* head=new node(-1,-1);
 node* tail=new node(-1,-1);
 unordered_map<int,node*>mpp;
 int cap;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deletenode(node* p)
    {
        node* previous=p->prev;
        node* nexti=p->next;
        previous->next=nexti;
        nexti->prev=previous;
    }
    void addnode(node* p)
    {
        p->next=head->next;
        head->next->prev=p;
        p->prev=head;
        head->next=p;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end())
        {
            node* r=mpp[key];
            int res=r->val;
            mpp.erase(key);
            deletenode(r);
            addnode(r);
            mpp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end())
        {
            node* ytr=mpp[key];
            deletenode(ytr);
            mpp.erase(key);
        }
        if(mpp.size()==cap)
        {
            node* curr=tail->prev;
            mpp.erase(curr->key);
            deletenode(tail->prev);
            
        }
       node* newnode=new node(key,value);
            addnode(newnode);
            mpp[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */