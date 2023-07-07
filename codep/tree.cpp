#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
vector<vector<ll>> edges;
vector<ll> sum, cnt, mx, tourist;
ll n, k;
const ll inf = 1e9;

ll dfs(int u, int p) {
    ll ans = 0;
    for (int child : edges[u]) {
        if (child == p)
            continue;
        ans += dfs(child, u);
        cnt[u] += cnt[child];
    }
    ans += cnt[u];
    cnt[u] += tourist[u];
    return ans;
}

void reroot(int u, int p, ll dist) {
    sum[u] = dist;
    for (ll child : edges[u]) {
        if (child != p) {
            reroot(child, u, dist + (k - cnt[child]) - cnt[child]);
        }
    }
}

pll farthesttourist(int u, int f, int p = -1, ll dis = 0) {
    pll ans = {-inf, u};
    if (f)
        mx[u] = max(mx[u], dis);
    if (tourist[u]) {
        ans.first = -1;
    }
    for (int child : edges[u]) {
        if (child != p) {
            ans = max(ans, farthesttourist(child, f, u, dis + 1));
        }
    }
    ans.first++;
    return ans;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        tourist = vector<ll>(n + 1);
        for (ll i = 0; i < k; i++) {
            ll x;
            cin >> x;
            tourist[x] = 1;
        }
        edges = vector<vector<ll>>(n + 1);
        for (ll i = 1; i < n; i++) {
            ll u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        cnt = vector<ll>(n + 1);
        sum = vector<ll>(n + 1);
        reroot(1, 1, dfs(1, 1));

        mx = vector<ll>(n + 1);
        farthesttourist(farthesttourist(farthesttourist(1, 0).second, 1).second,
                        1);

        pll ans = {inf, -1};

        for (int i = 1; i <= n; i++)
            ans = min(ans, pll(sum[i] - mx[i], i));

        cout << ans.second << '\n';
    }
}