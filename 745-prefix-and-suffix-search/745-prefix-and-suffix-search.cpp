class WordFilter {
public:
  unordered_map<string, set<int, greater<int>>> pref, suff;
  
  WordFilter(vector<string>& words) {
    for(int i = 0; i != words.size(); i++){
      string w = words[i];
      for(; !w.empty(); w.pop_back()) pref[w].insert(i);
      w = words[i]; reverse(w.begin(), w.end());
      for(; !w.empty(); w.pop_back()) suff[w].insert(i);
    }
  }
    
  int f(string prefix, string suffix) {
    reverse(suffix.begin(), suffix.end());
      
    for(auto id : pref[prefix])
      if(suff[suffix].count(id)) return id;
  
    return -1;
  }
};