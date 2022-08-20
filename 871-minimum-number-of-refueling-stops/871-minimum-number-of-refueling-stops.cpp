class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxReach = startFuel;
        priority_queue<int> pq;
        int count = 0;
        int index = 0;
            
        while(maxReach < target) {
            while(index < stations.size() && stations[index][0] <= maxReach) {
                pq.push(stations[index][1]);
                index++;
            }
            
            if(pq.empty()) return -1;
            maxReach += pq.top();
            pq.pop();
            count++;
        }
        
        return count;
    }
};