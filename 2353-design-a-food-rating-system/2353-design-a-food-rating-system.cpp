struct CustomCompare {
    bool operator()(pair<int,string> a, pair<int,string> b) const {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

class FoodRatings {
public:
    map<string,set<pair<int,string>, CustomCompare> > mp;
    map<string,string> items;
    map<string,int> index;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0 ; i<foods.size() ; i++) {
            items[foods[i]] = cuisines[i];
            mp[cuisines[i]].insert({ratings[i],foods[i]});
            index[foods[i]] = ratings[i];
        }
    } 
    
    void changeRating(string food, int newRating) {
        string cuisine = items[food];
        int rating = index[food];        
        
        mp[cuisine].erase({index[food],food});
        
        mp[cuisine].insert({newRating,food});
        
        index[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto it = mp[cuisine].rbegin();
        return it->second;
    }
};
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */