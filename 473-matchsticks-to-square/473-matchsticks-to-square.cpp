class Solution {
private:
    bool helper(int i, vector<int>& matchsticks, vector<int>& sides) {
        if(i == matchsticks.size()) {
            if(sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0) return true;
            return false;
        }
        
        for(int j = 0 ; j<4 ; j++) {
            if(matchsticks[i] <= sides[j]) {
                sides[j] -= matchsticks[i];
                if(helper(i+1,matchsticks,sides)) return true;
                sides[j] += matchsticks[i];
            }
        }
        
        return false;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false;
        
        int n = matchsticks.size();
        int perimeter = 0;
        
        for(int val : matchsticks) perimeter += val;
        
        int side = perimeter/4;
        
        if(perimeter % 4 != 0) return false;
        
        vector<int> sides(4,side);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return helper(0,matchsticks,sides);
    }
};