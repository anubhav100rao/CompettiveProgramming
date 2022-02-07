#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        set<char>contain;
        for(string &str: stickers) for(char &ch: str) contain.insert(ch);
        for(char &ch: target) if(!contain.count(ch)) return -1;

        int n = target.size(), m = (1 << n);
        const long long inf = (long long)1e11;
        vector<long long>dp(m, inf);

        dp[0] = 0;

        for(int i = 0; i<m; i++) { // every i represent some subset of target
            // i = 0 represent empty set and i = (1 << n) - 1 represent entire set
            if(dp[i] == inf) continue; // since we can't reach this subset
            for(string &str: stickers) {
                int superset = i; // this superset i represent that we have already made a set of i (i as subset)
                for(char &ch: str) {
                    for(int r = 0; r < n; r++) {
                        if(target[r] == ch && !((superset >> r) & 1)) {
                            superset |= (1 << r);
                            break;
                        }
                    }
                }
                dp[superset] = min(dp[superset], dp[i] + 1);
            }
        }        
        return dp[m-1];
        
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