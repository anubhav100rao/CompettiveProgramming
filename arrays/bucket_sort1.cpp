#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int solve(const vector<int>&arr) {
    
    int n = arr.size();
    if(n == 1)
        return 0;
    
    int mn = *min_element(arr.begin(), arr.end());
    int mx = *max_element(arr.begin(), arr.end());
    
    vector<int>max_bucket(n, INT_MIN);
    vector<int>min_bucket(n, INT_MAX);

    double delta = (mx - mn + 0.0) / (n - 1.0);

    for(int i = 0; i<n; i++) {
        if(arr[i] == mx || arr[i] == mn)
            continue;
        int idx = floor((arr[i] - mn) / delta);
        max_bucket[idx] = max(max_bucket[idx], arr[i]);
        min_bucket[idx] = min(min_bucket[idx], arr[i]);
    }

    int max_gap = 0;
    int pre_val = mn;
    for(int i = 0; i<n; i++) {
        if(min_bucket[i] == INT_MAX)
            continue;
        max_gap = max(max_gap, min_bucket[i] - pre_val);
        pre_val = max_bucket[i];
    }

    max_gap = max(max_gap, mx - pre_val);

    for(int i = 0; i<n; i++) {
        cout << max_bucket[i] << ' ' << min_bucket[i] << '\n';
    }

    return max_gap;
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
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    cout << solve(arr) << '\n';
    return 0;
}