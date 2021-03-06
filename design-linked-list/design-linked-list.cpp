class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head_=NULL;
        tail_=NULL;
        size_=0;
    }
    ~MyLinkedList(){
        Node* node=head_;
        while(node){
            Node* cur=node;
            node=node->next;
            delete cur;
        }
        head_=NULL;tail_=NULL;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0 || index>=size_) return -1;
        Node* node=head_;
        while(index--){
            node=node->next;
        }
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        head_=new Node(val,head_);
        if(size_++==0)
            tail_=head_;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto node=new Node(val);
        if(size_++==0)
            head_=tail_=node;
        else{
            tail_->next=node;
            tail_=tail_->next;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index<0 || index>size_) return;
        if(index==0) return addAtHead(val);
        if(index==size_) return addAtTail(val);
        Node dummy(0,head_);
        Node* pre=&dummy;
        while(index--) pre=pre->next;
        pre->next=new Node(val,pre->next);
        size_++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0 || index>=size_) return;
        Node dummy(0,head_);
        Node *pre=&dummy;
        for(int i=0;i<index;i++){
            pre=pre->next;
        }
        Node* tmp=pre->next;
        pre->next=pre->next->next;
        if(index==0) head_=pre->next;
        if(index==size_-1) tail_=pre;
        delete tmp;
        size_--;
    }
    
private:
    struct Node{
        int val;
        Node* next;
        Node():val(0),next(nullptr){}
        Node(int _val):val(_val),next(nullptr){}
        Node(int _val,Node* _next):val(_val),next(_next){}
    };
    Node* head_;
    Node* tail_;
    int size_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */