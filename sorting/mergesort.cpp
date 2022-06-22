#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<rightl

void merge(vector<int>&arr, int left, int mid, int right) {
    vector<int>res;
    int left_ptr = left, right_ptr = mid + 1;
    while(left_ptr <= mid and right_ptr <= right) {
        if(arr[left_ptr] < arr[right_ptr]) {
            res.push_back(arr[left_ptr++]);
        } else {
            res.push_back(arr[right_ptr++]);
        }
    }

    while(left_ptr <= mid) res.push_back(arr[left_ptr++]);
    while(right_ptr <= right) res.push_back(arr[right_ptr++]);

    for(int i = left; i <= right; i++) {
        arr[i] = res[i - left];
    }
}

void merge_sort(vector<int>&arr, int left, int right) {
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    int n; cin >> n;
    vector<int>arr(n, 0);
    for(int &i: arr) cin >> i;
    merge_sort(arr, 0, n - 1);
    for(int &i: arr) cout << i << " ";
    return 0;
}