#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<int>kthDijkstra(vector<vector<pair<int, int>>>&adj, int k, int source) {
    const int inf = 1e9 + 7;
    int n = adj.size();
    vector<vector<int>>dist(n, vector<int>(k, inf));
    for(int i = 0; i < k; i++) dist[source][i] = 0;
    vector<vector<bool>>visited(n, vector<bool>(k, false));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
    pq.push({0, 0, source}); // {dist, k, node}

    while(!pq.empty()) {
        vector<int>top = pq.top(); pq.pop();
        int node_distance = top[0], curr_k = top[1], node = top[2];
        if(visited[node][curr_k]) continue;
        visited[node][curr_k] = true;
        for(auto &[child, child_distance]: adj[node]) {
            if(!visited[child][curr_k] and dist[child][curr_k] > node_distance + child_distance) {
                dist[child][curr_k] = node_distance + child_distance;
                pq.push({dist[child][curr_k], curr_k, child});
            }

            if(curr_k + 1 < k and !visited[child][curr_k + 1] and dist[child][curr_k + 1] > node_distance) {
                dist[child][curr_k + 1] = node_distance;
                pq.push({dist[child][curr_k + 1], curr_k + 1, child}); 
            }
        }
    }   
    vector<int>min_dists(n);
    for(int i = 0; i < n; i++)
        min_dists[i] = dist[n - 1][k - 1];

    return min_dists;
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