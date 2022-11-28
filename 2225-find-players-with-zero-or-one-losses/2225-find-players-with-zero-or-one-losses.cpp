class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int> allMatches;
        map<int,int> allLoses;
        
        set<int> toRemoveFromWinner;
        
        for(vector<int>& match : matches) {
            int winner = match[0];
            int loser = match[1];
            
            allMatches[winner]++;
            allMatches[loser]++;

            allLoses[loser]++;
            toRemoveFromWinner.insert(loser);
        }
        
        vector<vector<int>> ans;
        
        vector<int> winners;
        vector<int> losers;
        
        for(auto& it : allMatches) {
            int player = it.first;
            int totalMatches = it.second;
            
            if(toRemoveFromWinner.find(player) != toRemoveFromWinner.end()) {
                if(allLoses[player] == 1) {
                    losers.push_back(player);
                }
            } else {
                winners.push_back(player);   
            }
        }
        
        ans.push_back(winners);
        ans.push_back(losers);
        
        return ans;
    }
};