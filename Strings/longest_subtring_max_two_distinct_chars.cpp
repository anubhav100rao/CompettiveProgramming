#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    // length of longest substring with atmax two distinct characters
    int solve(string &str) {
        map<char, int>seen;
        char pr = '$';
        int start = -1;
        int ans = 0;
        for(int i = 0; i<str.size(); i++) {
            if(seen.size() == 2 and !seen.count(str[i])) {
                int curr_min = 1e9;
                char toDel = '$';
                for(auto &[a, b]: seen) {
                    if(b < curr_min) {
                        curr_min = b;
                        toDel = a;
                    }
                }
                seen.erase(toDel);
                start = curr_min;
            }

            seen[str[i]] = i;
            ans = max(ans, i - start);
        }

        return ans;
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