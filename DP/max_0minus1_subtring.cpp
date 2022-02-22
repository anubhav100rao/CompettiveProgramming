#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    // idea is use kadane's algorithm
    // replace '0' -> 1 and '1' with -1
    int findLength(string &str) {
        int res = INT_MIN;
        int curr = 0;
        for(char &ch: str) {
            if(ch == '0') {
                curr++;
            } else {
                curr--;
            }
            res = max(res, curr);
            if(curr < 0) curr = 0;  
        }
        return res;
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