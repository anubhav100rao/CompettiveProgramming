#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [&](const auto &a, const auto &b) {
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });      
        // LONGEST INCREASING SUBSEQUENCE
        vector<int>res;
        for(int i = 0; i<n; i++) {
            auto it = lower_bound(res.begin(), res.end(), envelopes[i][1]);
            if(it == res.end())
                res.push_back(envelopes[i][1]);
            else
                *it = envelopes[i][1];
        }
        return res.size();
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