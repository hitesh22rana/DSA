class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
public:
    int countVowelSubstrings(string word) {
        int ans = 0, N = word.size();
        unordered_map<char, int> cnt;
        for (int i = 0; i < N; ++i) {
            cnt.clear();
            for (int j = i; j < N && isVowel(word[j]); ++j) {
                cnt[word[j]]++;
                if (cnt.size() == 5) ++ans;
            }
        }
        return ans;
    }
};