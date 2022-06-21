class Solution {
public:
    int furthestBuilding(vector<int>& heights, int b, int l) {
        priority_queue<int , vector<int> , greater<int> > pq;
        
        int n = heights.size();
        
        for(int i = 0 ; i<n-1 ; i++) {
            int diff = heights[i+1] - heights[i];
            
            if(diff > 0) {
                if(l != 0 && pq.size() < l) pq.push(diff);
                
                else {
                    if(!pq.empty() && diff > pq.top() && b >= pq.top()) {
                        b = b - pq.top();
                        pq.pop();
                        pq.push(diff);
                    }
                    else{
                        if(b >= diff) {
                            b = b-diff;
                        }
                        else return i;
                    }
                }
            }
            
        }
        return heights.size()-1;
    }
};