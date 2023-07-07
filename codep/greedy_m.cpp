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
    int n, k, m; cin >> n >> k >> m;
    vector<int>a(n), b(n), interested;
    int cnt = 0;
    for(int  &i: a) cin >> i;
    for(int  &i: b) cin >> i;
    for(int i = 0; i < n; i++) {
        if(a[i] >= k) {
            if(b[i] >= k) cnt++;
            else interested.push_back(b[i]);
        }
    }

    sort(interested.begin(), interested.end(), greater<int>());
    for(int i = 0; i < min(m, (int)interested.size()); i++) {
        if(interested[i] * 2 < k) break;
        cnt++;
    }

    cout << cnt;
    return 0;
}