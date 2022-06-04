#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    bool isPossible(vector<vector<bool>>&board, int n, int row, int col) {
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j]) {
                    if(row == i || col == j) return false;
                    if(row + j == col + i || row + col == i + j) return false;
                }
            }
        }
        return true;
    }
    
    void solve(vector<vector<bool>>&board, int n, int current_col, vector<vector<string>>&res) {
        if(current_col >= n) {
            vector<string>curr(n, string(n, '.'));
            for(int i = 0; i<n; i++)
                for(int j = 0; j<n; j++)
                    if(board[i][current_col])
                        curr[i][j] = 'Q';
            res.push_back(curr);
            return;
        }
        for(int i = 0; i<n; i++) {
            if(isPossible(board, n, i, current_col)) {
                board[i][current_col] = true;
                solve(board, n, current_col + 1, res);
                board[i][current_col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>>board(n, vector<bool>(n, false));
        vector<vector<string>>res;
        solve(board, n, 0, res);
        return res;
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