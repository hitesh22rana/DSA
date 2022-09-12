class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string greater;
        string small;
        string ans = "";
                
        if(str1 > str2) {
            greater = str1;
            small = str2;
        } else {
            greater = str2;
            small = str1;
        }
        
        string smaller = small;
        
        while(smaller.size() > 0) {
            if((greater.size() % smaller.size()) != 0 || (small.size() % smaller.size()) != 0) {
                smaller.pop_back();
                continue;
            }
            
            if(smaller == greater.substr(0,smaller.size())) {
                int start = smaller.size();
                bool flag = false;
                
                while(start < greater.size()) {
                    string check = greater.substr(start,smaller.size());

                    if(check.size() != smaller.size() || check != smaller) {
                        flag = true;
                        break;
                    }
                    
                    start += smaller.size();

                }
                
                int end = smaller.size();
                while(end < small.size()) {
                    string check = small.substr(end,smaller.size());

                    if(check.size() != smaller.size() || check != smaller) {
                        flag = true;
                        break;
                    }
                    
                    end += smaller.size();
                }
                
                if(!flag) return smaller;
            }
            
            if(smaller.size()) smaller.pop_back();
        }
        
        return "";
    }
};