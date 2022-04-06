#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

vector<int> getRow(int n) {
    
    vector<int>prev_state(n+1, 0);
    vector<int>curr_state(n+1, 0);
    prev_state[0] = 1;
    for(int i = 1; i<=n; i++) {
        // row i -> i+1 elements
        curr_state[0] = prev_state[0];
        curr_state[i] = prev_state[0];
        for(int j = 1; j<i; j++) {
            curr_state[j] = prev_state[j-1] + prev_state[j];
        }
        prev_state = curr_state;
    }
    return prev_state;;
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