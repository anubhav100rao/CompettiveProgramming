#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int numWays(string s) {
        int cnt = count(s.begin(), s.end(), '1');
        if(cnt % 3) return 0;
        cnt /= 3;
        int n = cnt;
        vector<int>res;
        
        int i = 0;
        while(i<s.size()) {
            while(i < s.size()) {
                if(s[i] == '1') cnt--;
                i++;
                if(cnt == 0) break;
            }     
            cnt = n;
            int z = 0;
            while(i < s.size() and s[i] == '0') {
                z++;
            }
            res.push_back(z);
        } 
        
        return (res[0] * 1LL * res[1]) % (1000000007);

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