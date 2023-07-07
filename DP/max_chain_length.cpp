#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct val{
	int first;
	int second;
};

class Solution{
public:
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        //Your code here
        sort(p, p + n, [&](struct val &a, struct val &b) {
            return a.second < b.second;
        });
        const int inf = INT_MAX;
        vector<int>dp(n + 1, inf);
        dp[0] = INT_MIN;

        for(int i = 0; i < n; i++) {
            int u = upper_bound(dp.begin(), dp.end(), p[i].first) - dp.begin();
            if(p[i].first > dp[u - 1] and dp[u] > p[i].second) {
                dp[u] = p[i].second;
            }
        }

        for(int i = n; i >= 0; i--)
            if(dp[i] != INT_MAX)
                return i;
        return 0;
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