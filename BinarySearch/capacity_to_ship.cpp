#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
  public:
    bool good(int arr[], int n, int days, int cap) {
        int cnt = 1;
        int curr = cap;
        int itr = 0;
        while(itr < n) {
            if(curr >= arr[itr]) {
                curr -= arr[itr];
                itr++;
            } else {
                cnt++;
                curr = cap;
            }
        }
        return cnt <= days;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        int l = *max_element(arr, arr + n), r = 1e9;
        int res = l;
        while(r - l >= 0) {
            int mid = l + (r - l) / 2;
            if(good(arr, n, d, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};



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