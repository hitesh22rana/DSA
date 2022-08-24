class Solution {
public:
    int len(long long int num) {
        int length = 0;
        while(num) {
            length++;
            num /= 10;
        }
        
        return length;
    }
    
    bool checker(vector<int> arr, long long int val) {
        while(val) {
            arr[val%10]--;
            val /= 10;
        }
        
        for(int i = 0 ; i<10 ; i++) {
            if(arr[i] != 0) return false;
        }
         
        return true;
    }
     
    bool reorderedPowerOf2(int n) {
        if(n == 0) return false;
        if(n <= 2) return true;
        
        vector<int> arr(10,0);
        int size = len(n);
        
        long long int num = n;

        while(num) {
            arr[num%10]++;
            num /= 10;
        }
        
        unordered_map<int,vector<long long int> > powersOfTwo;
        long long int power = 2;
        
        for(int i = 0 ; i<33 ; i++) {
            int length = len(power);
            powersOfTwo[length].push_back(power);
            power *= 2;
        }
        
        vector<long long int>& vec = powersOfTwo[size];
        
        for(long long int& val : vec) {
            if(checker(arr,val)) return true;
        }
        
        return false;
    }
};