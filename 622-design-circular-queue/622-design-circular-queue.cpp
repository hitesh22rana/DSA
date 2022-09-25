class MyCircularQueue {
public:
    vector<int> v;
    int cap , size ,front ,rear;
    MyCircularQueue(int k) {
        cap = k;
        size = 0 ;
        front = -1 ;
        rear = -1;
        v.resize(k);
    }

    bool enQueue(int value) {
        if(isFull()) return false;
        
        if(size == 0) {
            front = 0; 
            rear = 0;
            v[rear] = value;
        }
        
        else {
            rear = (rear + 1) % cap;
            v[rear]= value;
        }
        
        ++size;
        return true;

    }

    bool deQueue() {
        if(isEmpty()) return false;
        front = (front +1) % cap;
        --size;
        return true;
    }

    int Front() {
        if(isEmpty()) return -1; 
        return v[front];
    }

    int Rear() {
        if(isEmpty()) return -1;
        return v[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
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