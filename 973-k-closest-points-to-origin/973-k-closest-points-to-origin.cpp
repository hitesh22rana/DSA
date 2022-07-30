class comp {
    public:
        bool operator()(pair<vector<int>,double>& p1, pair<vector<int>,double>& p2) {
            return p1.second < p2.second;
        }
};

class Solution {
private:
    double distance(int x, int y) {
        return (double) sqrt(x*x + y*y);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<vector<int>,double> , vector<pair<vector<int>,double>> , comp> pq;;
        
        for(vector<int>& point : points) {
            double dist = distance(point[0],point[1]);
            
            if(pq.size() < k) {
                pq.push({point,dist});
            } else {
                if(dist < pq.top().second) {
                    pq.pop();
                    pq.push({point,dist});
                }            
            }
        }
        
        vector<vector<int>> ans;
        
        while(!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};