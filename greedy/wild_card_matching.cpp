#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int last_match = -1, marker = -1;
        while(i < s.size()) {
            if(j < p.size() and (s[i] == p[j] or p[j] == '?')) {
                i++;
                j++;
            } else if(j < p.size() and p[j] == '*') {
                marker = j;
                last_match = i;
                j++; // match to zero len
            } else if(marker != -1) {
                last_match++;
                i = last_match;
                j = marker + 1;
            } else {
                return false;
            }
        }
        
        while(j < p.size() and p[j] == '*') j++;
        
        return j == p.size();
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