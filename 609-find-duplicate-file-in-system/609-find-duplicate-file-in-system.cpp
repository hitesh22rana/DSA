class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        
        for(string path : paths) {
            int x = 0;
            string absolutePath;
            
            while(path[x] != ' ') {
                absolutePath.push_back(path[x++]);
            }
                                    
            while(x < path.size()) {
                string newPath;

                if(x < path.size() && path[x] == ' ') x++;
                
                while(x < path.size() && path[x] != '(') {
                    newPath.push_back(path[x++]);
                }
                x++;
                
                string content;
                while(x < path.size() && path[x] != ')') {
                    content.push_back(path[x++]);
                }
                x++;
                
                mp[content].push_back(absolutePath + "/" + newPath);
            }
        }
        
        for(auto it : mp) {
            if(it.second.size() > 1) ans.push_back(it.second);
        }
        
        return ans;
    }
};