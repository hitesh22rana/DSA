class Solution {
private:
    static bool compare(vector<int>& a , vector<int>& b) {
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
         vector<vector<int>> res;
    
        sort(people.begin(),people.end(),compare);

        for(auto &a : people) {
            res.insert(res.begin()+a[1],a);
        }
        return res;
    }
};