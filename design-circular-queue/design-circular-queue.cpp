class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        size=k;
        head=size-1;tail=0;cnt=0;
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        data[tail]=value;
        tail=(tail+1)%size;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        head=(head+1)%size;
        cnt--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:data[(head+1)%size];
    }
    
    int Rear() {
        return isEmpty()?-1:data[(tail-1+size)%size];
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==size;
    }
    
private:
        int head,tail,cnt,size;
        vector<int> data;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */