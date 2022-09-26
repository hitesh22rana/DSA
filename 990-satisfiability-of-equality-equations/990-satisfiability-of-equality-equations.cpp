class Solution {
public:
    vector<int> unionFind;

    int find(int x){
        return unionFind[x] == x ? x : find(unionFind[x]);
    }
    
    bool equationsPossible(vector<string>& equations) {        
        for(int i = 0 ; i<26 ; i++){
            unionFind.push_back(i);
        }
        
        for(string& equation : equations) {
            if(equation[1] == '=') {
                int p1 = find(equation[0] - 'a');
                int p2 = find(equation[3] - 'a');
                
                if(p1 != p2) {
                    unionFind[p2] = p1;
                }
            }
        }
    
        for(string& equation : equations) {
            if(equation[1] == '!') {
                int p1 = find(equation[0] - 'a');
                int p2 = find(equation[3] - 'a');
                
                if(p1 == p2) return false;
            }
        }

        return true;  
        
    }
};