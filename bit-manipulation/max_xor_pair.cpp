#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
    public:
    int max_xor(int a[] , int n)
    {
        int ans = 0;
        int mask = 0;

        for(int i = 30; i>=0; i--) {
            mask |= (1 << i);
            set<int>hsh;
            for(int j = 0; j<n; j++) {
                hsh.insert(a[j] & mask);
            }
            int newAns = ans | (1 << i);
            for(int pre: hsh) {
                if(hsh.count(pre ^ newAns)) {
                    ans = newAns;
                    break;
                }
            }
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