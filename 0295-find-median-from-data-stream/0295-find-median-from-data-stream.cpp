class MedianFinder {
private:
    int signumFunc(int miniSize , int maxiSize) {
        if(miniSize == maxiSize) return 0;
        else if(miniSize > maxiSize) return 1;
        return -1;
    }
    
    
    void callMedian(int element, priority_queue<int> &maxi , priority_queue<int,vector<int>,greater<int>> &mini , double &median) {

        switch(signumFunc(maxi.size() , mini.size())) {
            case 0:
                if(element > median) {
                    mini.push(element);
                    median = (double)mini.top();
                } else {
                    maxi.push(element);
                    median = (double)maxi.top();
                }
                break;

            case 1:
                if(element > median) {
                    mini.push(element);
                    median = (double)((double)mini.top() + (double)maxi.top())/2;
                } else {
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                    median = (double)((double)mini.top() + (double)maxi.top())/2;
                }
                break;

            case -1:
                if(element > median) {
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(element);
                    median = (double)((double)mini.top() + (double)maxi.top())/2;
                } else {
                    maxi.push(element);
                    median = (double)((double)mini.top() + (double)maxi.top())/2;
                }
                break;
        }
    }

public:
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    double median;
    
    MedianFinder() {
        this->median = 0;
    }
    
    void addNum(int num) {
        callMedian(num,maxi,mini,median);
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */