#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    vector<vector<int>>adj;
    int n;
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>>adj(n);
        for(auto &v: edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int>dp(n, -1);
        dp[0] = 0;        
        queue<int>q;
        q.push(0);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(int &child: adj[node]) {
                if(dp[child] == -1) {
                    dp[child] = dp[node] + 1;
                    q.push(child);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i<n; i++) {
            ans = max(ans, 2 * dp[i]);
            if(patience[i] < 2 * dp[i]) {
                int init_time = 2 * dp[i];
                int extra_msg = (init_time - 1) / patience[i];
                int last_extra_msg_time = extra_msg * patience[i] + init_time;
                ans = max(ans, last_extra_msg_time);
            }
        }
        ans++;
        return ans;
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