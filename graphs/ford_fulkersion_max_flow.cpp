#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

/**
 * flow = 0
 * while there is augmenting path from source to sink
 *          add this path-flow in flow
 * return flow
*/

bool bfs(vector<vector<int>>&residualGraph, int source, int sink, vector<int>&parent) {
    int n = parent.size();
    vector<bool>visited(n, false);
    queue<int>q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        for(int v = 0; v < n; v++) {
            if(!visited[v] and residualGraph[node][v] > 0) {
                if(v == sink) {
                    parent[v] = node;
                    return true;
                }
                q.push(v);
                parent[v] = node;
                visited[v] = true;
            }
        }
    }

    return false;
}

int fordFulkerson(vector<vector<int>>&graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>>residualGraph = graph;
    vector<int>parent(n, -1);
    int max_flow = 0;

    while(bfs(residualGraph, source, sink, parent)) {
        int path_flow = INT_MAX;
        for(int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, residualGraph[u][v]);
        }

        for(int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= path_flow;
            residualGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
        
    }

    return max_flow;
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