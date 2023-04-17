//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int ceil(int arr[], int n, int x) {
    int start = 0;
    int end = n - 1;
    
    while(start <= end) {
        int mid = start + (end - start) / 2;
        
        if(arr[mid] >= x) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    if(start == - 1 || start >= n) return -1;
    
    return arr[start];
}

int floor(int arr[], int n, int x) {
    int start = 0;
    int end = n - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        
        if(arr[mid] > x) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    if(end == -1 || end >= n) return -1;
    
    return arr[end];
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr, arr + n);
    int floorValue = floor(arr, n, x);
    int ceilValue = ceil(arr, n, x);
    
    return {floorValue, ceilValue};
}