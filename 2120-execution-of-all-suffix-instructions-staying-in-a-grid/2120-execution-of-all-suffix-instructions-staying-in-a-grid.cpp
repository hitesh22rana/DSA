class Solution {
public:
    int countSteps(int gridSize, int i, int j, string s) {
        int steps = 0;
        
        for(char& c : s) {
            if(c == 'R') j++;
            else if(c == 'L') j--;
            else if(c == 'U') i--;
            else if(c == 'D') i++;
            
            if(i < 0 || j < 0 || i >= gridSize || j >= gridSize) break;
            
            steps++;
        }
        
        return steps;
    }
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        
        for(int i = 0 ; i<s.size() ; i++) {
            string str = s.substr(i,s.size());
            ans.push_back(countSteps(n,startPos[0],startPos[1],str));
        }
        
        return ans;
    }
};