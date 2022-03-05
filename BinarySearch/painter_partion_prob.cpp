#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution
{
    using ll = long long;
public:
    bool good(int arr[], int n, int k, int t) {
        int curr = t;
        int itr = 0;
        
        if(t < *max_element(arr, arr + n))
            return false;
        int cnt = 1;
        while(itr < n) {
            if(curr >= arr[itr]) {
                curr -= arr[itr];
                itr++;
            } else {
                cnt++;
                curr = t;
            }
        }
        return cnt <= k;
    } 
    
    long long minTime(int arr[], int n, int k)
    {
        ll l = 1, r = 1e9;
        ll res = 1;
        while(r - l >= 0) {
            ll mid = l + (r - l) / 2;
            if(good(arr, n, k, mid)) {
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