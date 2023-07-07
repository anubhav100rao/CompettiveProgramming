#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    int n; cin >> n;
    vector<int>A(n), B(n);
    for(int i = 0; i < n; i++) cin >> A[i];   
    for(int i = 0; i < n; i++) cin >> B[i]; 

    vector<int>pref(n), suff(n);
    pref[0] = (A[0] >= B[0]);
    suff[n - 1] = (A[n - 1] >= B[n - 1]);

    for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + (A[i] >= B[i]);
    for(int i = n - 2; i >= 0; i--) suff[i] = suff[i + 1] + (A[i] >= B[i]);

    auto good = [&](const int mid) {

        int cnt = 0;
        for(int left = 0, right = 0; right < n; right++) {
            if(A[right] * 2 >= B[right]) cnt++;

            if(right - left + 1 > mid) {
                if(A[left] * 2 >= B[left]) cnt--;
                left++;
            }

            int curr = (left - 1 >= 0 ? pref[left - 1]: 0)
                + cnt +
              (right + 1 < n ? suff[right + 1]: 0);


            if(curr >= n - curr) return true;
        } 

        return false;
    };

    int left = 0, right = n, res = -1;

 
    while(right - left >= 0) {
        int mid = left + (right - left) / 2;
        if(good(mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << res;

    return 0;
}