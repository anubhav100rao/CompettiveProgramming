#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int n, m;
    vector<vector<char>>arr;  
    vector<vector<bool>>visited;
    string str;

    vector<int>dx = {0, 0, -1, 1};
    vector<int>dy = {1, -1, 0, 0};  
    
    bool good(const int x, const int y) {
        if(x < 0 || x >= n || y < 0 || y >= m) return false;
        return !visited[x][y];
    };

    bool dfs(int x, int y, int idx) {
        if(idx >= str.size()) return true;
        visited[x][y] = true;
        bool flag = false;
        for(int i = 0; i<4; i++) {
            int new_x = x + dx[i], new_y = y + dy[i];
            if(good(new_x, new_y)) {
                if(str[idx] == arr[new_x][new_y])
                    flag = flag || dfs(new_x, new_y, idx + 1);
                if(flag) return true;
            }
        }
        return visited[x][y] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        str = word;
        arr = board;

        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        bool flag = false;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(arr[i][j] == str[0]) {
                    visited = vector<vector<bool>>(n, vector<bool>(m, false));
                    flag = flag || dfs(i, j, 1);
                    if(flag) return true;
                }
            }
        }

        return flag;
        
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