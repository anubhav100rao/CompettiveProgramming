#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int n, m;
    vector<vector<char>>grid;
    const int LEFT = 0;
    const int RIGHT = 1;
    vector<vector<vector<int>>>dp;

    int solve(int i, int j, int dir) {
        if(i >= n || i < 0) return 0;
        if(j >= m || j < 0) return 0;

        if(grid[i][j] == '#')
            return 0;
        
        if(dp[i][j][dir] != -1)
            return dp[i][j][dir];

        int curr = (grid[i][j] == 'E') ? 0 : 1;

        if(dir == RIGHT) {
            return dp[i][j][dir] = curr + max({
                solve(i, j+1, RIGHT),
                solve(i+1, j, LEFT)
            });
        } else {
            return dp[i][j][dir] = curr + max({
                solve(i, j-1, LEFT),
                solve(i+1, j, RIGHT)
            });
        }
    }

    int collectMaxCoins(vector<vector<char>>&grid) {
        this->grid = grid;
        this->n = grid.size();
        this->m = grid[0].size();
        dp = vector<vector<vector<int>>>(n+1, vector<vector<int>>(m+1, vector<int>(2, -1)));
        return solve(0, 0, RIGHT);
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<char>>grid = { {'E', 'C', 'C', 'C', 'C'},
                       {'C', '#', 'C', '#', 'E'},
                       {'#', 'C', 'C', '#', 'C'},
                       {'C', 'E', 'E', 'C', 'E'},
                       {'C', 'E', '#', 'C', 'E'}
                     };
    Solution anubhav;
    cout << anubhav.collectMaxCoins(grid);
    return 0;
}