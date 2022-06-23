#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int val = 0, cnt = 0, pow = 1;
        for (int i = s.size() - 1; i >= 0 && val + pow <= k; --i) {
            if (s[i] == '1') {
                ++cnt;
                val += pow;
            }
            pow <<= 1;
        }
        return count(begin(s), end(s), '0') + cnt;
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