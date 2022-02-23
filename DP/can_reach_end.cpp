#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
  public:
    int canReach(int arr[], int n) {
        // code here
        const int inf = 1e9;
        if(n == 0 || arr[0] == 0)
            return 0;
        
        int mx = 0;
        
        for(int i = 0; i<n; i++) {
            if(i > mx) {
                return 0;
            }
            mx = max(mx, i + arr[i]);
        }
        return 1;
        
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