class Solution {
public:
    vector<bool> bitConverter(int data) {
        vector<bool> ans(8);
        for(int i = 0 ; i<8 ; i++) {
            ans[8-i-1] = data&1;
            data >>= 1;
        }
        
        return ans;
    }
    
    int type(vector<bool>& bitMap) {
        int count = 0;
        for(int i = 0 ; i<bitMap.size() ; i++) {
            if(bitMap[i]) count++;
            else break;
        }

        return count;
    }
    
    bool validUtf8(vector<int>& data) {
        for(int i = 0 ; i<data.size() ; i++) {
            vector<bool> bitMap = bitConverter(data[i]);

            int val = type(bitMap);
            int j = i+1;

            if(val == 1 || val > 4 || val > data.size() - i) return false;
            
            while(j < data.size() && val > 1) {
                vector<bool> bits = bitConverter(data[j]);
                if(type(bits) != 1) return false;
                j++;
                val--;
            }
            
            i = j-1;
        }
        
        return true;
    }
};