class Solution {
private:
    static bool compare(pair<int,string> &a , pair<int,string> &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        
        for(string word : words) {
            mp[word]++;
        }
        
        vector<pair<int,string> > values;
        
        for(auto &it : mp) {
            values.push_back(make_pair(it.second,it.first));
        }
        
        sort(values.begin(),values.end(),compare);
        
        vector<string> ans;
        
        for(auto &it : values) {
            if(!k) break;
            ans.push_back(it.second);
            k--;
        }
        
        return ans;
    }
};