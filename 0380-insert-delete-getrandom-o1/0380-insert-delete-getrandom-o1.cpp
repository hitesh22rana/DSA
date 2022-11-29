class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) {
            return false;
        }
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int last = nums.back();
        mp[last] = mp[val];
        nums[mp[val]] = last;
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }    
};