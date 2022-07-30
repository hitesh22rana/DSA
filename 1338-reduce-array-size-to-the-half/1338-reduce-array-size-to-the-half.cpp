class comp {
    public:
        bool operator()(pair<int,int>& p1, pair<int,int>& p2){
            return p1.second < p2.second;
        }
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        map<int,int> mp;        
        int half = arr.size()/2;
        
        for(int& val : arr) {
            mp[val]++;
        }
        
        int count = 0;
        int size = 0;
        
        for(auto& it : mp) {
            pq.push({it.first,it.second});
        }
        
        while(!pq.empty()) {
            count++;
            size += pq.top().second;
            pq.pop();
            if(size >= half) return count;
        }
        
        return count;
    }
};