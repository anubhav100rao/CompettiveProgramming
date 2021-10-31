#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"
const int N = 3e5 + 5;
int top, q;
int n, m;
vector<int>g[N];
int f[N], cnt[N], st[N], X[N], Y[N];

int gf(int node) {
    return f[node] == node ? node : f[node] = gf(f[node]);
}

void dfs1(int node, int parent, int to) { // search in tree and print that path
    st[++top] = node; // marking the entry time
    if(node == to) {
        cout << top << "\n";
        for(int i = 1; i<=top; i++) {
            cout << st[i] << " ";
        }
        cout << "\n";
    }
    for(int child: g[node]) if(child^parent) dfs1(child, node, to); // same as if(child != parent)
    top--;
}
vector<int>path;
void dfs(int node, int parent, int to) { // search in tree and print that path
    path.push_back(node);
    if(node == to) {
        cout << path.size() << "\n";
        for(int el: path) cout << el << " ";
        cout << "\n";
    }
    for(int child: g[node]) if(child != parent) dfs(child, node, to);
    path.pop_back();
}

signed main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
  
    cin >> n >> m;
    for(int i = 1; i<=n; i++) f[i] = i;
    for(int i = 1, x, y; i<=m; i++) {
        cin >> x >> y;
        if(gf(x) != gf(y)) {
            g[x].push_back(y);
            g[y].push_back(x);//this is the way to create spanning tree : adding edge iff it don't form cycle
            f[gf(x)] = gf(y); // path compression
        }
    }

    int sum = 0;
    cin >> q;
    for(int i = 1; i<=q; i++) {
        cin >> X[i] >> Y[i];
        cnt[X[i]]++, cnt[Y[i]]++;
    }
    for(int i = 1; i<=n; i++) if(cnt[i] & 1) sum++;
    if(sum)  cout << "NO\n" << sum/2 << "\n";
    else {
        cout << "YES\n";
        for(int i = 1; i<=q; i++) dfs(X[i], 0, Y[i]);
    }
    return 0;
}