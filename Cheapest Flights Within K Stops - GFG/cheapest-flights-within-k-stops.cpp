//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<pair<int, int>> adj[n];

        for(auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        queue<vector<int>> q;
        q.push({0, src, 0});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while(!q.empty()) {
            vector<int> flight = q.front();
            q.pop();

            int stops = flight[0];
            int node = flight[1];
            int cost = flight[2];

            if(stops > k) continue;
            
            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int edW = it.second;
                
                if(cost + edW < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, adjNode, cost + edW});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends