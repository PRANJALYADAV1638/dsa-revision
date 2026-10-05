/*

class LFUCache {
public:
 class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node*freq;
        Node* next;

        Node(int k,int v){
            key=k;
            value=v;
            prev=NULL;
            freq=NULL;
            next=NULL;
        }
    };

int capacity;
unordered_map<int , Node> mp;
Node* head;
Node* tail;
int size;
    LFUCache(int capa) {
        cap=capacity;
size=0;
 head=new Node(-1,-1);
        tail=new Node(-1,-1);

head->next=tail;
tail->prev=head;


    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->value=value;
            node->freq++;
            node->prev->next=node->next;
            node->next->prev=node->prev;
            node->next=head->next;
            node->prev=head;
            head->next->prev=node;
            head->next=node;
            size++;
        }
       Node* node=new Node(key);
       mp[key]=node;
      node->freq++;
       node->next=head->next;
       node->prev=head;
       head->next->prev=node;
       head->next=node;
       size++;
       if(size>capacity){
        int min=freq[0];
    for(int b=0;b<freq.size();b++){
if(freq[b]<min){
    min =freq;
}

    }
    
       }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
