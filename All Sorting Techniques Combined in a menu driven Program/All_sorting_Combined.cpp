#include<bits/stdc++.h>
using namespace std;


// Bubble Sort
void bubbleSort(vector<int> &arr , int n) {
    for(int i = 0 ; i<n ; i++) {
        for(int j = 0 ; j<n-i-1 ; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}


// Selection Sort
int findminindex(vector<int> &arr , int s , int e) {
    int mini = arr[s];
    int minindex = s;
    for(int i = s ; i<=e ; i++) {
        if(arr[i] < mini) {
            mini = arr[i];
            minindex = i;
        }
    }
    return minindex;
}

void selectionSort(vector<int> &arr , int n) {
    int min;
    for(int i = 0 ; i<n-1 ; i++) {
        min = findminindex(arr , i , n-1);
        swap(arr[min] , arr[i]);
    }
}


// Insertion Sort
void insertionSort(vector<int> &arr , int n) {
    for(int i = 0 ; i<n ; i++) {
        for(int j = i ; j>0 ; j--) {
            if(arr[j] < arr[j-1]) {
                swap(arr[j] , arr[j-1]);
            }
        }
    }
}


// Merge Sort
void merge(vector<int> &arr , int s , int e) {
    int i = s;
    int mid = s + ((e-s)>>1);
    int j = mid+1;
    vector<int> temp;

    while(i <= mid && j <= e) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }

        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= e) {
        temp.push_back(arr[j]);
        j++;
    }

    int k = 0;

    for(int indx = s ; indx <= e ; indx++) {
        arr[indx] = temp[k];
        k++;
    }
}

void mergeSort(vector<int> &arr , int s , int e) {
    if(s >= e) {
        return;
    }
    int mid = s + ((e-s)>>1);
    mergeSort(arr , s , mid);
    mergeSort(arr , mid+1 , e);
    merge(arr , s , e);
}


// Quick Sort
int partition(vector<int> &arr , int s , int e) {
    int pivot = arr[e];
    int i = s;

    for(int j = s ; j<e ; j++) {
        if(arr[j] < pivot) {
            swap(arr[i] , arr[j]);
            i++;
        }
    }

    swap(arr[i] , arr[e]);
    return i;
}

void quickSort(vector<int> &arr , int s , int e) {
    if(s >= e) {
        return;
    }
    int p = partition(arr , s , e);
    quickSort(arr , s , p-1);
    quickSort(arr , p+1 , e);
}


// Print Function
void print(vector<int> &arr) {
    for(int val : arr) {
        cout<<val<<" ";
    }
    cout<<"\n";
}

int main() {

    cout<<"Welcome!!"<<"\n";
    int n;
    cout<<"Enter size of the Array : ";
    cin>>n;
    cout<<"\n";
    vector<int> arr;
    int ele;
    for(int i = 0 ; i<n ; i++) {
        cout<<"Element at "<<i+1<<" position : ";
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"\n";
    cout<<"Select one of the following Sorting technique given below using which you want to Sort your given Array\n\n";
    cout<<"1 -> for using Bubble Sort\n";
    cout<<"2 -> for using Selection Sort\n";
    cout<<"3 -> for using Insertion Sort\n";
    cout<<"4 -> for using Merge Sort\n";
    cout<<"5 -> for using Quick Sort\n\n";
    cout<<"Type the number : ";
    
    int type;
    cin>>type;

    switch(type) {
        
        case 1:
            bubbleSort(arr , n);
            cout<<"Sorted Array after sorting with Bubble Sort : ";
            print(arr);
            break;

        case 2:
            bubbleSort(arr , n);
            cout<<"Sorted Array after sorting with Selection Sort : ";
            print(arr);
            break;

        case 3:
            insertionSort(arr , n);
            cout<<"Sorted Array after sorting with Insertion Sort : ";
            print(arr);
            break;

        case 4:
            mergeSort(arr , 0 , n-1);
            cout<<"Sorted Array after sorting with Merge Sort : ";
            print(arr);
            break;

        case 5: 
            quickSort(arr , 0 , n-1);
            cout<<"Sorted Array after sorting with Quick Sort : ";
            print(arr);
            break;

        default:
            cout<<"Enter Valid Number : \n";
            break;
    }
    
    return 0;
}