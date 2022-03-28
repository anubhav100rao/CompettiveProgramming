#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int longestSubsequenceCommonSegment(int k, string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>>lcs(n+1, vector<int>(m+1, 0));
    vector<vector<int>>cnt(n+1, vector<int>(m+1, 0));
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            if(s1[i-1] == s2[j-1])
                cnt[i][j] = cnt[i-1][j-1] + 1;
            
            if(cnt[i][j] >= k) {
                for(int len = k; len <= cnt[i][j]; len++) {
                    lcs[i][j] = lcs[i-len][j-len] + len;
                }
            }
        }
    }
    return lcs[n][m];
}


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