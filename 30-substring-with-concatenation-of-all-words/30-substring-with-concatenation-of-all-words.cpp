class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].size();
        int totalWords = words.size();
        int n = s.size();
        vector<int> ans;
        
        unordered_map<string,int> freq;
        
        for(string& word : words) {
            freq[word]++;
        }
        
        for(int i = 0 ; i<=n-wordLength*totalWords ; i++) {
            unordered_map<string,int> seenWords;
            
            for(int j = 0 ; j<totalWords ; j++) {
                int wordIndex = i+j*wordLength;
                string word = s.substr(wordIndex,wordLength);
                
                if(freq.find(word) == freq.end()) break;
                
                seenWords[word]++;
                
                if(seenWords[word] > freq[word]) break;
                
                if(j+1 == totalWords) ans.push_back(i);
            }
            
        }
        
        return ans;
    }
};