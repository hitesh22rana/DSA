//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> ans;
        
        int start1 = 0;
        int start2 = 0;
        
        while(start1 < n && start2 < m) {
            if(arr1[start1] <= arr2[start2]) {
                if(ans.size() == 0 || ans.back() != arr1[start1]) {
                    ans.push_back(arr1[start1]);
                }
                start1++;
            } else {
                if(ans.size() == 0 || ans.back() != arr2[start2]) {
                    ans.push_back(arr2[start2]);
                }
                start2++;
            }
        }
        
        while(start1 < n) {
            if(ans.back() != arr1[start1]) {
                ans.push_back(arr1[start1]);
            }
            start1++;
        }
        
        while(start2 < m) {
            if(ans.back() != arr2[start2]) {
                ans.push_back(arr2[start2]);
            }
            start2++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends