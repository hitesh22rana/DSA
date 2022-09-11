class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return 1;
        
        sort(intervals.begin(),intervals.end());

        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto& interval : intervals) {
            if(!pq.empty() && pq.top() < interval[0]) {
                pq.pop();
            }
            pq.push(interval[1]);
        }
        
        return pq.size();
    }
};