class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string str;
        int count = 0;
        
        for(int i = 0 ; i<n ; i++) {
            int freq = 0;
            
            int j = i;
            while(j < n && chars[j] == chars[i]) {
                j++;
                freq++;
            }
            
            str.push_back(chars[i]);
            i = j - 1;
            
            count++;
            
            if(freq > 1) {
                str += to_string(freq);
                while(freq) {
                    count++;
                    freq /= 10;
                }
            }
        }
        
        int index = 0;
        for(char& c : str) {
            chars[index++] = c;
        }
        
        return count;
    }
};