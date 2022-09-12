class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if(n <= 0) return 0;
        
        sort(tokens.begin(),tokens.end());
        
        if(tokens[0] > power) return 0;
        
        int start = 0, end = n-1;
        int score = 0;
        
        while(start <= end){
            if(tokens[start] <= power) {
                score++;
                power -= tokens[start++];
            }
            else if (score >= 1 && start < end){
                score--;
                power += tokens[end--];
            }
            else break;
        }
        return score;
    }
};