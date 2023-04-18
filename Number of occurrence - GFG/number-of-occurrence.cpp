//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int lower(int arr[], int n, int x) {
	    int start = 0;
	    int end = n-1;
	    
	    while(start <= end) {
	        int mid = end + (start - end) / 2;
	        
	        if(arr[mid] >= x) {
	            end = mid - 1;
	        } else {
	            start = mid + 1;
	        }
	    }
	    
	    return start;
	}
	
	int upper(int arr[], int n, int x) {
	    int start = 0;
	    int end = n-1;
	    
	    while(start <= end) {
	        int mid = start + (end - start) / 2;
	        
	        if(arr[mid] <= x) {
	            start = mid + 1;
	        } else {
	            end = mid - 1;
	        }
	    }
	    
	    return end;
	}
	
	int count(int arr[], int n, int x) {
	    return upper(arr, n, x) - lower(arr, n, x) + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends