#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});

        string res = "";
        while(!pq.empty()) {
            auto [fre, ch] = pq.top(); pq.pop();
            if(res.size() > 1 and res[0] == ch and res[1] == ch) {
                if(pq.empty()) break;
                auto [fre_next, ch_next] = pq.top(); pq.pop();
                res.push_back(ch_next);
                fre_next--;
                if(fre_next > 0)
                    pq.push({fre_next, ch_next});
            } else {
                fre--;
                res.push_back(ch);
            }

            if(fre > 0) {
                pq.push({fre, ch});
            }
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