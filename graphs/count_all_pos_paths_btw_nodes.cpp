#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

/*
input
nodes edges
a1 b1
a2 b2
.
.
.
aedges bedges
source destination

key backtraking observation

after visiting all neighbours of node
    visited[node] = false;
*/

class CountAllPossiblePaths {
public:
    int nodes, edges;
    vector<vector<int>>adj;
    vector<bool>visited;
    int source, destination;
    int count_paths = 0;
    void read_graph() {
        cin >> nodes >> edges;
        adj = vector<vector<int>>(nodes + 1);
        for(int i = 0; i<edges; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cin >> source >> destination;
        visited = vector<bool>(nodes + 1, false);
    }

    void dfs(int src) {
        visited[src] = true;
        if(src == destination) count_paths++;
        else {
            for(int &child: adj[src]) if(!visited[child]) {
                dfs(child);
            }
        }
        visited[src] = false;
    }

    int get_count() {
        dfs(source);
        return count_paths;
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
    CountAllPossiblePaths anubhav;
    anubhav.read_graph();
    cout << anubhav.get_count() << '\n';
    return 0;
}