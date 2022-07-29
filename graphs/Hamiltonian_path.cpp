#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

// Hamiltonian path

class Solution
{
public:
    bool check(int N, int M, vector<vector<int>> Edges)
    {
        vector<vector<bool>> adj(N, vector<bool>(N, false));
        for (auto e : Edges)
        {
            adj[e[0] - 1][e[1] - 1] = true;
            adj[e[1] - 1][e[0] - 1] = true;
        }

        vector<vector<bool>> dp(N, vector<bool>(1 << N, false));

        for (int i = 0; i < N; i++)
        {
            dp[i][1 << i] = true;
        }

        for (int i = 0; i < (1 << N); i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i & (1 << j))
                {
                    for (int k = 0; k < N; k++)
                    {
                        if (i & (1 << k) && adj[k][j] && j != k && dp[k][i ^ (1 << j)])
                        {
                            dp[j][i] = true;
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dp[i][(1 << N) - 1])
                return true;
        }

        return false;
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
 
    return 0;
}