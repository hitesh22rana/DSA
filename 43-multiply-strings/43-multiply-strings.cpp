class Solution {
public:
    string addStrings(string num1, string num2) {
        string str = "";
        
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        
        while(i >= 0 || j >= 0 || carry != 0) {      
            int ival = i >= 0 ? num1[i] - '0' : 0;
            int jval = j >= 0 ? num2[j] - '0' : 0;
            i--;
            j--;
            int sum = ival + jval + carry;
            str = to_string(sum%10) + str;
            carry = sum/10;
        }
        
        return str;
    }
    
    string multiply(string num1, string num2) {       
        string upperNum = num1 > num2 ? num1 : num2;
        string lowerNum = num1 > num2 ? num2 : num1;
        
        int len1 = upperNum.size();
        int len2 = lowerNum.size();
        
        string ans = "";
            
        for(int i = len2-1 ; i>=0 ; i--) {
            int num = lowerNum[i] - '0';
            string str;
            int carry = 0;
            
            for(int j = len1-1 ; j>=0 ; j--) {
                int multiply = num * (upperNum[j] - '0') + carry;
                
                if(j == 0) {
                    str = to_string(multiply) + str;
                } else {
                    int ones = multiply % 10;
                    int tens = multiply / 10;
                    carry = tens;

                    str = to_string(ones) + str;                  
                }
                
            }
            
            for(int k = 0 ; k<len2-i-1 ; k++) {
                str.push_back('0');
            }
            
            ans = addStrings(ans,str);
        }
        
        reverse(ans.begin(),ans.end());
        
        for(int i = ans.size() - 1 ; i>0 ; i--) {
            if(ans[i] == '0') {
                ans.pop_back();
            } else {
                break;
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};