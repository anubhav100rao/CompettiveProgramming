#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // bfs + binary search
        // 🚀🚀
        
        vector<int>dx = {-1, 1, 0, 0};
        vector<int>dy = {0, 0, -1, 1};
        

        auto good = [&](const int x, const int y) {
            if(x < 0 || x >= row || y < 0 || y >= col) 
                return false;
            return true;
        };

        auto bfs = [&](const int day) {
            vector<vector<bool>>island(row, vector<bool>(col, true));
            vector<vector<bool>>visited(row, vector<bool>(col, false));
            for(int i = 0; i<day; i++)
                island[cells[i][0] - 1][cells[i][1] - 1] = false;
            queue<pair<int, int>>q;
            for(int i = 0; i<col; i++)
                if(island[0][i])
                    q.push({0, i}), visited[0][i] = false;
            
            while(!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                if(x == row - 1)
                    return true;
                for(int i = 0; i<4; i++) {
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];
                    if(!good(new_x, new_y) || visited[new_x][new_y] || !island[new_x][new_y])
                        continue;
                    visited[new_x][new_y] = true;
                    q.push({new_x, new_y});
                }
            }
            return false;
        };

        int l = 0, r = row * col - 1;
        int res = 0;
        while(r - l >= 0) {
            int mid = l + (r - l) / 2;
            if(bfs(mid)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
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