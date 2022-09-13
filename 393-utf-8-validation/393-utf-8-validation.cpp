class Solution {
public:
    string bitConverter(int data) {
        string ans;
        
        for(int i = 0 ; i<8 ; i++) {
            int val = data % 2;
            ans = to_string(val) + ans;
            data >>= 1;
        }
        
        return ans;
    }
    
    int type(string& bitMap) {
        int count = 0;
        for(int i = 0 ; i<bitMap.size() ; i++) {
            if(bitMap[i] == '1') count++;
            else break;
        }
        
        return count;
    }
    
    bool validUtf8(vector<int>& data) {
        for(int i = 0 ; i<data.size() ; i++) {
            string bitMap = bitConverter(data[i]);

            int val = type(bitMap);
            int j = i+1;

            if(val == 1 || val > 4 || val > data.size() - i) return false;
            
            while(j < data.size() && val > 1) {
                string bits = bitConverter(data[j]);
                if(type(bits) != 1) return false;
                j++;
                val--;
            }
            
            i = j-1;
        }
        
        return true;
    }
};