class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        
        unordered_map<int,int> mp;
        sort(hand.begin(),hand.end());
        
        for(int& num : hand) {
            mp[num]++;
        }        
        
        for(int& num : hand) {
            if(mp[num] <= 0) continue;

            for(int start = num ; start<num+groupSize ; start++) {
                if(mp[start] <= 0) return false;
                mp[start]--;
            }
            
        }
        
        return true;
    }
};