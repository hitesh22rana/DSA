class Word {
public:
    int val;
    string word;
    
    Word(int _val , string _word) {
        this->val = _val;
        this->word = _word;
    }
};

class compare {
public:
    bool operator()(Word &a , Word &b) {
        if(a.val == b.val) return a.word > b.word;
        return a.val < b.val;
    }
};

class Solution {    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        
        for(string word : words) {
            mp[word]++;
        }
        
        priority_queue<Word , vector<Word> ,  compare> values;
        
        for(auto &it : mp) {
            values.push(Word(it.second,it.first));
        }
        
        vector<string> ans;
        
        while(!values.empty()) {
            if(!k) break;
            ans.push_back(values.top().word);
            values.pop();
            k--;
        }
        
        return ans;
    }
};