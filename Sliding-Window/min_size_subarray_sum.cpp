#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n+1, 0);
        for(int i = 1; i<=n; i++)
            pre[i] = pre[i-1] + nums[i-1];
        
        if(pre[n] < target)
            return 0;
        int len = INT_MAX;
        for(int i = n; i>=0 and pre[i] >= target; i--) {
            int j = upper_bound(pre.begin(), pre.end(), pre[i] - target) - pre.begin();
            len = min(len, i - j + 1);
        }
        return len;
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