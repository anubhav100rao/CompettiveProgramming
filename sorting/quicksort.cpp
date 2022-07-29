#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int partition(vector<int>&arr, int low, int high) {
    int i = low, j = high, pivot = arr[low];

    while(i <= j) {
        while(i <= j and arr[i] <= pivot) i++;
        while(i <= j and arr[j] > pivot) j--;
        if(i <= j) swap(arr[i], arr[j]);
    }
    /**
     * left pivot element
     * middle pivot element
     * last pivot element
     * randomised quick sort
     */
    swap(arr[low], arr[j]);
    
    return j;
}

int partition_maintain(vector<int>&a, int low, int high) {
        int n = a.size();
        vector<int>result(high - low + 1, 0);
        int pivot = a[0];
        int idx = 0;
        for(int i = 0; i<n; i++) {
            if(a[i] < pivot) {
                result[idx] = a[i];
                idx++;
            }
        }

        for(int i = 0; i<n; i++) {
            if(a[i] == pivot) {
                result[idx] = a[i];
                idx++;
            }
        }

        for(int i = 0; i<n; i++) {
            if(a[i] > pivot) {
                result[idx] = a[i];
                idx++;
            }
        }

        for(int i: result)
            cout << i << " ";
}


void quick_sort(vector<int>&arr, int low, int high) {
    if(low >= high) return;

    int pivot = partition(arr, low, high);

    quick_sort(arr, low, pivot);
    quick_sort(arr, pivot + 1, high);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
 
    return 0;
}