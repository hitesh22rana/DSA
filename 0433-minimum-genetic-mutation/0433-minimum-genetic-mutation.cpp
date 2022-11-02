class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(bank.size() <= 0) return -1;
        unordered_set<string> st(bank.begin(), bank.end());
        if(st.find(end) == st.end()) return -1;
        
        queue<pair<string,int> > q;
        q.push({start, 0});
        
        unordered_set<string> visited;
        visited.insert(start);
        
        while(!q.empty()) {
            pair<string,int> str = q.front();
            q.pop();
            
            string gene = str.first;
            int level = str.second;
            
            if(gene == end) return level;
            
            string letters = "ACGT";
            for(int i = 0 ; i<8 ; i++) {
                
                for(char& c : letters) {
                    string newGene = gene.substr(0,i) + c + gene.substr(i+1, 8);
                    
                    if((visited.find(newGene) == visited.end()) && (st.find(newGene) != st.end())) {
                        q.push({newGene, level+1});
                        visited.insert(newGene);
                    }
                }
            }
        }
        
        return -1;
    }
};