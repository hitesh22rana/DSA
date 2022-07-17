class Data {
public:
    int index;
    string val;
    
    Data(int index, string val) {
        this->index = index;
        this->val = val;
    }
};

class compare {
public:
    bool operator()(Data &a, Data &b) {
        if(a.val == b.val) return a.index < b.index;
        return a.val < b.val;
    }
};

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();
        
        for(vector<int>& query : queries) {
            int trimSize = query[1];
            int k = query[0];
            
            priority_queue<Data,vector<Data>,compare> pq;
            
            for(int i = 0 ; i<n ; i++) {
                string val = nums[i];
                int size = val.size() - trimSize;
                string num = val.substr(size,val.size());
                
                if(pq.size() >= k) {
                    if(pq.top().val > num) {
                        pq.pop();
                        Data value(i,num);
                        pq.push(value);
                    }
                } else {
                    Data value(i,num);
                    pq.push(value);
                }
                
            }
            
            ans.push_back(pq.top().index);
        }
        
        return ans;
    }
};