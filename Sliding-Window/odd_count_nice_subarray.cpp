#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    int solve(vector<int>&nums, int k) {
        if(k <= 0) return 0;
        int l = 0, r = 0, n = nums.size(), cnt = 0, res = 0;
        while(r < n) {
            if(cnt == k and nums[r] & 1) {
                while(!(nums[l] & 1)) {
                    l++;
                };
                cnt--;
                l++;
            }
            if(nums[r] & 1) cnt++;
            res += (r - l + 1);
            r++;
        }
        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
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