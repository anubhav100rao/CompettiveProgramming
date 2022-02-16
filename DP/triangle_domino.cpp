#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int count_ways(int n) {
        vector<int>A(n+1, 0), B(n+1, 0);
        A[0] = 1, B[0] = 0;
        A[1] = 0, B[1] = 1;
        for(int i = 2; i<=n; i++) {
            A[i] = A[i-2] + 2 * B[i-1];
            B[i] = A[i-1] + B[i-2];
        }
        return A[n];
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