class Solution {
private:
    int minCost(vector<int>& cost, int indx, vector<int>& dp) {        
        if(indx == 0) return cost[0];
        if(indx == 1) return cost[1];
        if(dp[indx]) return dp[indx];
        return dp[indx] = min(minCost(cost,indx-1, dp) + cost[indx], minCost(cost,indx-2, dp) + cost[indx]);
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),0);
        return min(minCost(cost,cost.size()-1,dp),minCost(cost,cost.size()-2,dp));   
    }
};