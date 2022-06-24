class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long int sum = 0;
        
        for(int val : target) {
            pq.push(val);
            sum += val;
        }
        
        while(pq.top() != 1) {
            int top = pq.top();
            pq.pop();
            sum -= top;
            
            if(sum >= top || sum < 1) return false;
            
            top %= sum;
            
            sum += top;
            
            if(top > 0) pq.push(top);
            else pq.push(sum);  
        }
        
        return true;
    }
};