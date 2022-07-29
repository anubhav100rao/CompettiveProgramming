#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int>arr(n, 0);
    for(int &i: arr) cin >> i;

    auto good = [&](const int sz) {
        int need = 0;
        for(int &i: arr) {
            need += (i + sz - 1) / sz;
        }

        return need <= m;
    };

    int l = 1, r = m;
    int res = 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(good(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << res << "\n";

    return 0;
}