class Solution {
public:
    int findEquationValue(pair<int,int>& p1, pair<int,int>& p2, pair<int,int> p3) {
        int x1 = p1.first;
        int y1 = p1.second;
        
        int x2 = p2.first;
        int y2 = p2.second;
        
        int x3 = p3.first;
        int y3 = p3.second;
        
        return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> ans;
       
        sort(trees.begin(), trees.end());

        deque<pair<int,int>> lower;
        deque<pair<int,int>> upper;
        
        for(vector<int>& point : trees) {
            int lowerSize = lower.size();
            int upperSize = upper.size();
            
            while(lowerSize >= 2 && findEquationValue(lower[lowerSize - 2], lower[lowerSize - 1], {point[0], point[1]}) < 0) {
                lowerSize--;
                lower.pop_back();
            }
            
            while(upperSize >= 2 && findEquationValue(upper[upperSize - 2], upper[upperSize - 1], {point[0], point[1]}) > 0) {
                upperSize--;
                upper.pop_back();
            }
            
            lower.push_back({point[0], point[1]});
            upper.push_back({point[0], point[1]});
        }
        
        set<pair<int,int>> st;
        
        for(pair<int,int>& point : lower) st.insert(point);
        for(pair<int,int>& point : upper) st.insert(point);
        
        for(auto& it : st) {
            ans.push_back({it.first, it.second});
        }
        
        return ans;
    }
};