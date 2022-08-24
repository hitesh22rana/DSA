class Solution {
public:
    unordered_set<long long int> st;
    
    bool checkPowersOfThree(int n) {
        if(n <= 1) return true;
        if(n <= 2) return false;
        
        long long int powerOfThree = 3;
        for(int i = 0 ; i<33 ; i++) {
            if(powerOfThree*3 == n) return true;
            if(powerOfThree*3 > n) {
                if(st.find(powerOfThree) != st.end()) return false;
                int num = n - powerOfThree;
                st.insert(powerOfThree);
                if(st.find(num) != st.end()) return false;
                return checkPowersOfThree(num);
            }
            
            powerOfThree *= 3;
        }
        
        return false;
    }
};