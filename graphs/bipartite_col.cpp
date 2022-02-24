#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

/**
 * Given a connected graph with N vertices. The task is to select k(k must be less than or equals to n/2, not necessarily *      * minimum) vertices from the graph such that all these selected vertices are connected to at least one of the non selected * * *   vertex. In case of multiple answers print any one of them.
*/

int n, m;
vector<vector<int>>adj;
vector<bool>visited;
vector<vector<int>>states(2);

void dfs(int node, int state) {
    visited[node] = true;
    states[state].push_back(node);
    for(int &child: adj[node]) {
        if(!visited[child]) {
            dfs(child, state ^ 1);
        }
    }
}

vector<int>col;
void bfs(int start) {
    queue<int>q;
    q.push(start);
    col[start] = 0;
    visited[start] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int &child: adj[node]) {
            if(!visited[child]) {
                visited[child] = true;
                col[child] = col[node] ^ 1;
                q.push(child);
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