#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0;

        set<int>seen;
        int ans = 0;

        while(r < n) {
            if(seen.count(nums[r])) {
                while(nums[l] != nums[r]) {
                    seen.erase(nums[l]);
                    sum -= nums[l++];
                } sum -= nums[l++];
            }
            seen.insert(nums[r]);
            sum += nums[r++];
            ans = max(ans, sum);
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