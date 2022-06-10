#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int>hsh;
        int ans = 1e9;
        for(int i = 0; i<cards.size(); i++) {
            if(hsh.count(cards[i])) {
                ans = min(ans, i - hsh[cards[i] ]+ 1);
            }
            hsh[cards[i]] = i;
        }
        return ans == 1e9 ? -1 : ans;
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