#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

vector<int>sub;
vector<int>wt;
vector<vector<int>>adj;

void dfs_subtree(int node, int parent) {
    sub[node] = 1;
    for(int &child: adj[node]) {
        if(child != parent) {
            dfs_subtree(child, node);
            sub[node] += sub[child];
        }
    }
}

void dec_sub() {
    for(int &i: sub) {
        if(i)
            i--;
    }
}

void dfs_wt(int node, int parent) {
    for(int &child: adj[node]) {
        if(child != parent) {
            dfs_wt(child, node);
            wt[node] += wt[child] + sub[child];
        }
    }
}

void show_vector(vector<int>&arr) {
    for(int i: arr)
        cout << i << " ";
    cout << "\n";
}


void dfs(int node, int parent) {
    for(int &child: adj[node]) {
        if(child == parent)
            continue;
        wt[child] = wt[node] + sub[node] - 2 * sub[child];
        dfs(child, node);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    int n, m; cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    sub = vector<int>(n+1, 0);
    wt = vector<int>(n+1, 0);

    for(int i = 0; i<m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_subtree(1, 0);
    show_vector(sub);
    // dec_sub();
    dfs_wt(1, 0);
    show_vector(wt);
    dfs(1, 0);
    show_vector(wt);
    return 0;
}