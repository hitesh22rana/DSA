class Solution {
private:
    string check(int n) {
        if(n%3 == 0 && n%5 == 0) return "FizzBuzz";
        if(n%3 == 0) return "Fizz";
        if(n%5 == 0) return "Buzz";
        return to_string(n);
    }
    
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        
        for(int i = 1 ; i<=n ; i++) {
            ans[i-1] = check(i);
        }
        
        return ans;
    }
};