class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(!(p&1) && !(q&1)) {
            p = p>>1;
            q = q>>1;
        }
        
        if(!(p&1)) return 2;
        
        if(!(q&1)) return 0;
        
        return 1;
        
    }
};