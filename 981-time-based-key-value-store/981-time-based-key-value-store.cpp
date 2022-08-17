class TimeMap {
public:
    int search(vector<pair<string,int> >& arr, int& timestamp) {
        int start = 0;
        int end = arr.size() - 1;
        int ans = -1;
        int mid;
        
        while(start <= end) {
            mid = start + (end - start) / 2;
            
            if(arr[mid].second == timestamp) {
                return mid;
            } else if(arr[mid].second < timestamp) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid-1;
            }
        }
        
        return ans;
    }
    
    unordered_map<string,vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(value,timestamp));
    }
    
    string get(string key, int timestamp) {
        int index = search(mp[key],timestamp);
        if(index == -1) return "";
        return mp[key][index].first;
    }
};