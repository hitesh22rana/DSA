class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        
        for(vector<int>& vec : matrix) {
            for(int& val : vec) {
                if(pq.size() < k) {
                    pq.push(val);
                } else {
                    if(pq.top() > val) {
                        pq.pop();
                        pq.push(val);
                    }
                }
            }
        }
        
        return pq.top();
    }
};