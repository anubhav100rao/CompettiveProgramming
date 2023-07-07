#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif


using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

#define int long long

const int inf = 1e16;

int n, m, k; 
vector<int>arr, brr, crr;
vector<vector<int>>adj;
vector<vector<int>>dp;
int complete_set = 0;



int solve(int idx, int mask) {
    
    if(idx >= k) {
        if((mask & complete_set) == complete_set) return 0;

        return inf;
    }

    if(dp[idx][mask] != -1) return dp[idx][mask];

    int updated_mask = mask;
    for(const int m: adj[idx]) {
        updated_mask |= (1 << m);
    }
    return dp[idx][mask] = min(solve(idx + 1, mask), crr[idx] + solve(idx + 1, updated_mask));

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    
    cin >> n >> m >> k;
    arr = vector<int>(n), brr = vector<int>(m), crr = vector<int>(k);
    for(int i = 0; i < n; i++) { cin >> arr[i]; arr[i]--; }
    for(int i = 0; i < m; i++) { cin >> brr[i]; brr[i]--; }
    for(int i = 0; i < k; i++) cin >> crr[i];

    debug(arr); debug(brr); debug(crr);
    adj = vector<vector<int>>(k);
    for(int i = 0; i < k; i++) {
        int course_count; cin >> course_count;
        for(int j = 0; j < course_count; j++) {
            int x; cin >> x; x--;
            adj[i].push_back(x);
        }
    }

    debug(adj);
    set<int>avail(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
        complete_set |= (1 << arr[i]);
    debug(complete_set);
    int mask = 0;
    for(int i = 0; i < m; i++)
        if(avail.count(brr[i]))
            mask |= (1 << brr[i]);
    debug(mask);
    

    dp = vector<vector<int>>(k, vector<int>(1e5, -1));

    int ans = solve(0, mask);
    if(ans >= inf) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}