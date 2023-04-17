//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int>>& arr, int n, int m) {
	    int ans = -1;
	    int maxi = 0;
	    
	    for(int i = 0 ; i<n ; i++) {
	        int start = 0;
	        int end = m-1;
	           
	       while(start <= end) {
	           int mid = start + (end - start) / 2;
	           
	           if(arr[i][mid] == 0) {
	               start = mid + 1;
	           } else {
	               end = mid - 1;
	           }
	       }
	       
	       if((m - start) > maxi) {
	           maxi = m - start;
	           ans = i;
	       }
	    }
	    
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends