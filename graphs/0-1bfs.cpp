#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
const int INF = 1e15;
vector<vector<pair<int, int>>>adj;

void z1_bfs(int n) {
    vector<int>dis(n+1, INF);
    deque<int>q;
    q.push_front(1);
    dis[1] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop_front();
        for(auto [child, wt]: adj[node]) {
            if(dis[node] + wt < dis[child]) {
                dis[child] = dis[node] + wt;
                if(wt == 1) q.push_back(child);
                else q.push_front(child);
            }
        }
    }
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