class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        
        vector<char> values;
        vector<int> forces(n,0);
        
        for(char& c : dominoes) values.push_back(c);
        
        int force = 0;
        for(int i = 0 ; i<n ; i++) {
            if(dominoes[i] == 'R') {
                force = n;
            } else if(dominoes[i] == 'L') {
                force = 0;
            } else {
                force = max(force - 1 , 0);
            }
            forces[i] += force;
        }
        
        force = 0;
        for(int i = n-1 ; i>=0 ; i--) {
            if(dominoes[i] == 'L') {
                force = n;
            } else if(dominoes[i] == 'R') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            forces[i] -= force;
        }
        
        string ans;
        
        for(int& force : forces) {
            char val = force > 0 ? 'R' : (force == 0 ? '.' : 'L');
            ans.push_back(val);
        }
        
        return ans;
    }
};