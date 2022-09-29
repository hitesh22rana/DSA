class cmp {
public:
    bool operator()(pair<int,int>& p1, pair<int,int>& p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        
        for(int& val : arr) {
            int absValue = abs(val - x);

            if(pq.size() < k) {
                pq.push(make_pair(absValue,val));
            } else {
                if(pq.top().first > absValue) {
                    pq.pop();
                    pq.push(make_pair(absValue,val));
                }
            } 
        }
        
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};