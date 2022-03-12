#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    
    using pii = pair<char, int>;
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int>hsh;
        int mx = 0;
        for(char &task: tasks) {
            hsh[task]++;
            mx = max(mx, hsh[task]);
        }

        int ans = (mx - 1) * (n + 1);
        
        for(auto [a, b]: hsh)
            ans += (b == mx);
        return max((int)tasks.size(), ans);
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