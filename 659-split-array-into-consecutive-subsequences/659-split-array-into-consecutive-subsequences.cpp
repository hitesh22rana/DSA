class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> counter;
        unordered_map<int,int> end;
        
        for(int& num : nums) {
            counter[num]++;
        }
        
        for(int& num : nums) {
            if(!counter[num]) continue;
            
            counter[num]--;
            
            if(end[num-1] > 0) {
                end[num-1]--;
                end[num]++;
            }
                
            else if(counter[num+1] && counter[num+2]){
                counter[num+1]--;
                counter[num+2]--;
                end[num+2]++;
            }
            else return false;
        }
        
        return true;
    }
};