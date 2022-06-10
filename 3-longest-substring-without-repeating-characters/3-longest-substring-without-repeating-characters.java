class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s == null || s.length() == 0) {
            return 0;
        }
        
        int len = s.length();
        int start = 0;
        int end = 0;
        int maxlength = 0;
        char ch;
        
        Set<Character> uniquechar = new HashSet<>();
        
        while(end < len) {
            ch = s.charAt(end);
            
            while(uniquechar.contains(ch)) {
                uniquechar.remove(s.charAt(start));
                start++;
            }
            
            uniquechar.add(ch);
            maxlength = Math.max(maxlength , end - start+1);
            end++;
        }
        
        return maxlength;
    }
}