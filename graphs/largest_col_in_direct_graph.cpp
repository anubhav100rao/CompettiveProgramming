#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), ans = 0, cnt = 0;
        vector<vector<int>>adj(n), dp(n, vector<int>(26, 0));
        vector<int>in(n);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            in[edge[1]]++;
        }
        queue<int>q;
        for(int i = 0; i<n; i++) if(in[i] == 0) {
            q.push(i);
            dp[i][colors[i]-'a'] = 1;
        }
        while(!q.empty()) {
            int node = q.front(); q.pop();
            cnt++;
            ans = max(ans, dp[node][colors[node] - 'a']);
            for(int &child: adj[node]) {
                in[child]--;
                for(int i = 0; i<26; i++)
                    dp[child][i] = max(dp[child][i], dp[node][i] + (colors[child] == 'a' + i));
                if(in[child] == 0)
                    q.push(child);
            }
        }   
        if(cnt < n) return -1;
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