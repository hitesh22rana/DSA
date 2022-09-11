class Solution {
public:
    int MOD = 1e9+7;
    
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        if(v1[0] == v2[0]) return v1[1] > v2[1];
        return v1[0] > v2[0];
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> engineers;
        
        for(int i = 0 ; i<n ; i++) {
            engineers.push_back({efficiency[i],speed[i]});
        }
        
        sort(engineers.begin(),engineers.end(), cmp);
                
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long long int ans = 0;
        long long int totalSpeed = 0;
        
        for(int i = 0 ; i<n ; i++) {
            if(pq.size() == k) {
                totalSpeed -= pq.top();
                pq.pop();
            }
            
            totalSpeed += engineers[i][1];
            pq.push(engineers[i][1]);
            
            ans = max(ans,engineers[i][0] * totalSpeed);
        }
        
        return ans % MOD;
    }
};