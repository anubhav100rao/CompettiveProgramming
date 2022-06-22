#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp_inc(n, 1);
        for(int i = 1; i<n; i++)
            for(int j = 0; j<i; j++)
                if(arr[i] > arr[j])
                    dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1);
        vector<int>dp_dec(n, 1);
        for(int i = n-2; i>=0; i--) {
            for(int j = n-1; j>i; j--) {
                if(arr[i] > arr[j]) {
                    dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);
                }
            }
        }

        int res = n;
        for(int i = 1; i<n-1; i++) {
            if(dp_inc[i] > 1 and dp_dec[i] > 1)
                res = min(res, n -  (dp_inc[i] + dp_dec[i] - 1));
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