#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

struct compare {
    bool operator()(int a, int b) {
        return a < b;
    }
};

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>>dp(n, vector<int>(n, 0));
    int itr = 1;
    
    int i = 0, j = 0;
    int l = 0;
    int r = 1;
    auto operate = [&]() {
        if(l == 0 and r == 1) {
            l = 1;
            r = 0;
            // cout << "hitted first\n";
        } else if(l == 1 and r == 0) {
            r = -1;
            l = 0;

            // cout << l << ' ' << r << " -- this --" << " hitted second\n";
        } else if(l == 0 and r == -1) {
            l = -1;
            // cout << "hitted third\n";
            r = 0;
        } else if(l == -1 and r == 0) {
            l = 0;
            r = 1;
            
        } else {
            
           
        }
    };

    auto check = [&](const int x, const int y) {
        
        if(x < 0 || x >= n) return false;
        if(y < 0 || y >= n) return false;
        if(dp[x][y] != 0)
            return false;
        return true;
    };

    auto next_move = [&]() {
        i += l;
        j += r;
    };

    auto revert_move = [&]() {
        i -= l;
        j -= r;
    };

    while(itr <= n*n) {
        dp[i][j] = itr++;
        next_move();
        if(!check(i, j)) {
            revert_move();
            operate();
            // cout << "prev accident -> " <<  i << ' ' << j << '\n';
            // cout << "moves " << l << ' ' << r << '\n';
            next_move();
            // cout << "during accident -> " << i << ' ' << j << '\n';
            if(!check(i, j)) break;
        }
        
    }

    

    return dp;

}



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    int n; cin >> n;
    vector<vector<int>>dp = generateMatrix(n);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cout << dp[i][j] << ' ';
        } cout << '\n';
    }
    return 0;
}