class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        unordered_map<int,priority_queue<int>> mp;
        int minAttack = INT_MAX;
        int maxAttack = 0;
        
        for(vector<int>& property : properties) {
            minAttack = min(minAttack,property[0]);
            maxAttack = max(maxAttack,property[0]);
            mp[property[0]].push(property[1]);
        }
        
        int count = 0;
        int maxDefence = -1;
        
        for(int i = maxAttack ; i>=minAttack ; i--) {
            if(mp.find(i) == mp.end()) continue;
            
            priority_queue<int>& pq = mp[i];    
            int maxi = pq.top();
            
            while(!pq.empty() && pq.top() >= maxDefence) {
                pq.pop();
            }
            
            count += pq.size();
            maxDefence = max(maxi,maxDefence);
        }        
        
        return count;
    }
};