#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"


//********Debug Snippet********/
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
string to_string(bool b) {return (b ? "true" : "false");}
string to_string(vector<bool> v) {bool first = true;string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}
template <size_t N>
string to_string(bitset<N> v) {string res = "";for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]);}return res;}
template <typename A>
string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}
template <typename A, typename B>
string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
 
//**********DEBUGING OVER************/

int tot;
const int inf = 1e16;
const int neg_inf = -1e16;

vector<vector<int>>dp;

int solve_min(vector<int>&arr, int idx, int curr, int contain) {
    if(contain < 0)
        return inf;
    if(idx < 0) {
        if(contain == 0) {
            return curr * (tot - curr);
        }
        return inf;
    }

    if(dp[idx][contain] != -1)
        return dp[idx][contain];

    return dp[idx][contain] = min(
            solve_min(arr, idx - 1, curr, contain),
            solve_min(arr, idx - 1, curr + arr[idx], contain - 1)
        );

}


int solve_max(vector<int>&arr, int contain) {
    const int N = 2501;
    bool dp[arr.size() + 10][contain + 10][N + 10];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i<=arr.size(); i++) {
        dp[i][0][0] = true;
    }
    for(int i = 1; i<=arr.size(); i++) {
        for(int j = 1; j<=contain; j++) {
            for(int k = 1; k<=N; k++) {
                dp[i][j][k] = dp[i-1][j][k];
                if(arr[i-1] <= k) {
                    dp[i][j][k] = dp[i][j][k] || dp[i-1][j-1][k - arr[i-1]];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i<=N; i++) {
        if(dp[arr.size()][contain][i]) {
            ans = max(ans, i * (tot - i));
        }
    }
    return ans;
}

vector<int>maxMinValues(vector<int>&arr, int n, int m) {
    assert(arr.size() == n + m);
    // sort(arr.begin(), arr.end());
    vector<int>res;

    tot = accumulate(arr.begin(), arr.end(), 0LL);

    dp = vector<vector<int>>(n + m + 1, vector<int>(n + 1, -1));
    res.push_back(solve_min(arr, n + m - 1, 0, n));
    res.push_back(solve_max(arr, n));

    return res;

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
    vector<int>arr(n + m, 0);
    for(int &i: arr)
        cin >> i;

    vector<int>res = maxMinValues(arr, n, m);

    for(int i: res) cout << i << ' '; cout << '\n';

    return 0;
}