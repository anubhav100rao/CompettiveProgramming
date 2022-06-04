#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int countPairs(vector<int>&arr) {
    int n = arr.size();
    // count pairs a[i] & a[j] = 0
    // if a[i] & a[j] = 0 => a[i] | a[j] = a[i] ^ a[j]
    int tot = (n * (n - 1)) / 2;
    for(int i = 0; i<31; i++) {
        int cnt = 0;
        for(int j: arr) {
            if((1 << i) & j)
                cnt++;
        } 
        tot -= (cnt * (cnt - 1)) / 2;
    }
    return tot;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    vector<int>arr = {3, 4, 2};
    cout << countPairs(arr);
    return 0;
}