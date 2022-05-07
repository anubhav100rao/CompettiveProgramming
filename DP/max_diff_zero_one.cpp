#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int maxDiffZeroOne(string &str) {
    int ans = -1;
    int curr = 0;
    int n = str.size();
    for(int i = 0; i<n; i++) {
        if(str[i] == '1')
            curr--;
        else
            curr++;

        ans = max(ans, curr);
        if(curr < 0)
            curr = 0;
    }
    return ans;
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