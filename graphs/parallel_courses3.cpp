#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution { // standard topo sort questions
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n + 1);
        vector<int>in(n + 1);
        for(auto &edge: relations) {
            adj[edge[0]].push_back(edge[1]);
            in[edge[1]]++;
        }
        vector<int>dp(n + 1);
        for(int i = 0; i<n; i++)
            dp[i+1] = time[i];
        queue<int>q;
        for(int i = 1; i<=n; i++) {
            if(in[i] == 0) {
                q.push(i);
            }
        }

        int ans = 0;



        while(!q.empty()) {
            int node = q.front(); q.pop();
            ans = max(ans, dp[node]);
            for(int &child: adj[node]) {
                in[child]--;
                dp[child] = max(dp[child], dp[node] + time[child - 1]);
                if(in[child] == 0) {
                    q.push(child);
                }
            }
        }

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