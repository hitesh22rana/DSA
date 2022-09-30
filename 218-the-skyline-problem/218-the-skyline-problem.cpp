class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int,int>> values;
        
        for(auto& it:buildings){
            values.push_back(make_pair(it[0],-it[2]));
            values.push_back(make_pair(it[1],it[2]));
        }
        
        multiset<int> pq;
        pq.insert(0);
        int height = 0;
        
        sort(values.begin(),values.end());
        
        for(auto& it:values){
            int curr_point = it.first;
            int curr_height = it.second;
            
            if(curr_height<0){
                pq.insert(abs(curr_height));
            }
            else{
                pq.erase(pq.find(curr_height));
            }
            
            int pqtop = *pq.rbegin();
            
            if(pqtop != height){
                height = pqtop;
                ans.push_back({curr_point,height});
            }
        }
        return ans;
    }
};