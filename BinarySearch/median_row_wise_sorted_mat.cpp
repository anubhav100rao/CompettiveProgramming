#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){        
        int mn = INT_MAX, mx = INT_MIN;
        
        for(int i = 0; i<r; i++) {
            mn = min(mn, matrix[i][0]);
            mx = max(mx, matrix[i][c-1]);
        }
        
        int req = (r * c + 1) / 2;
        int res = mn;
        while(mx - mn > 0) {
            int mid = mn + (mx - mn) / 2;
            int have = 0;
            for(int i = 0; i<r; i++) {
                have += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(have < req) {
                mn = mid + 1;
            } else {
                mx = mid;
            }
        }
        return mn;
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