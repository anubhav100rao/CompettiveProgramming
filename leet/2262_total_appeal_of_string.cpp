#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    long long appealSum(string s) {
        long long cur = 0, res = 0;
        vector<long long>last(26, 0);
        int n = s.size();
        for(int i = 0; i<n; i++) {
            cur += i + 1 - last[s[i] - 'a'];
            last[s[i] - 'a'] = i+1;
            res += cur;
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