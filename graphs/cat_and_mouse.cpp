#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    const int inf = 1e9 + 7;
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>dist(n + 1, inf);
        dist[0] = 0;
        queue<int>q;
        vector<bool>visited(n + 1, false);
        visited[0] = true;

        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(int &child: graph[node]) {
                if(!visited[child]) {
                    visited[child] = true;
                    q.push(child);
                    dist[child] = dist[node] + 1;
                }
            }
        }

        if(dist[1] <= dist[2]) return 1;

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