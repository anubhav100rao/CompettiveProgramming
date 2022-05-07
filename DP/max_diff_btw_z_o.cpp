#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

int countMaxDiffZeroOne(string &str) {
    if(!count(str.begin(), str.end(), '0'))
        return -1;
    
    int n = str.size();

    int ans = 0;
    int curr = 0;
    for(char ch: str) {
        if(ch == '0') {
            curr++;
        } else curr--;

        ans = max(ans, curr);
        if(curr <= 0)
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