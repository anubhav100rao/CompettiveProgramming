#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>seen;
        int start = -1, ans = 0;
        for(int i = 0; i<s.size(); i++) {
            if(seen.count(s[i]))
                start = max(start, seen[s[i]]);
            seen[s[i]] = i;
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