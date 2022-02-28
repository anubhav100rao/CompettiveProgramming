#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

const int UN_VISITED = 0;
const int IN_DFS = 1;
const int COMPLETED = 2;
bool flag = false;
vector<vector<int>>adj;
vector<int>color;
// Univisited = 0
// in dfs = 1
// completed dfs = 2

void dfs(int node) {
    color[node] = IN_DFS;
    for(int &child: adj[node]) {
        if(color[child] == UN_VISITED) {
            dfs(child);
        } else if(color[child] == IN_DFS) {
            flag = true;
        }
        // no case when color is COMPLETED
    }
    color[node] = 2;
}

bool detect_cycle(int n) {
    color = vector<int>(n+1, UN_VISITED);
    flag = false;
    for(int i = 1; i<=n; i++) {
        if(color[i] == UN_VISITED) {
            dfs(i);
        }
    }
    return flag;
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