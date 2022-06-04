#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<int>F, A;

void solve() {
    int n = A.size();
    for (int mask = 0; mask < (1<<n); mask++){
        F[mask] = A[0];
        // iterate over all the subsets of the mask
        for(int i = mask; i > 0; i = (i-1) & mask){
            F[mask] += A[i];
        }
    }
}

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