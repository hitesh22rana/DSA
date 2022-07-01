class Solution {
private:
    static bool compare(vector<int>& box1 , vector<int>& box2) {
        return box1[1] > box2[1];
    }
    
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int n = boxTypes.size();
        
        int count = 0;
        int ans = 0;
        
        
        for(int i = 0 ; i<n ; i++) {
            int value = boxTypes[i][1];
            int total = boxTypes[i][0];
            
            while(total > 0 && count <= truckSize) {
                count++;
                total--;
                
                if(count > truckSize) break;
                
                ans += value;
            }
            
        }   
        
        return ans;
    }
};