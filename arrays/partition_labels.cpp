#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int>last;
        int n = s.size();
        for(int i = 0; i<n; i++)
            last[s[i]] = i;
        vector<int>res;
        for(int i = 0; i<n; ) {
            int curr = last[s[i]];
            int j = i;
            while(j <= curr) {
                curr = max(curr, last[s[j]]);
                j++;
            }
            res.push_back(j - i);
            i = j;
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