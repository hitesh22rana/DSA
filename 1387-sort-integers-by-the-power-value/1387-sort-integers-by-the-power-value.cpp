class cmp {
public:
    bool operator()(pair<long long int,long long int>& p1, pair<long long int,long long int>& p2) {
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second;
    }
};

class Solution {
public:
    unordered_map<long long int,long long int> dp;
    
    long long int power(long long int x) {
        if(x == 1) return 0;
        
        if(dp.find(x) != dp.end()) return (long long int)dp[x];        
        
        else if(x & 1) {
            return dp[x] = 1 + power((long long int)3*x+1);
        }
        
        return dp[x] = 1 + power(x/2);
    }
    
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>, cmp> pq;
        
        for(int i = lo ; i<=hi ; i++) {
            pair<long long int,long long int> p = {i,power(i)};
                
            if(pq.size() < k) {
                pq.push(p);
            } else {
                if(pq.top().second == p.second) {
                    if(pq.top().first > p.first) {
                        pq.pop();
                        pq.push(p);
                    }
                } else if(pq.top().second > p.second) {
                    pq.pop();
                    pq.push(p);
                }
            }
        }

        return pq.top().first;
    }
};