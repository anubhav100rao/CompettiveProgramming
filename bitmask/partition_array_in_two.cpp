#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl


class Solution {
public:

    int setbits(int mask) {
        return __builtin_popcount(mask);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return abs(nums[0] - nums[1]);
        vector<int>arr, brr;
        for(int i = 0; i<n; i++) {
            if(i & 1) brr.push_back(nums[i]);
            else arr.push_back(nums[i]);
        }
        vector<vector<int>>arr_pre(30), brr_pre(30);
        for(int mask = 1; mask < (1 << (int)arr.size()); mask++) {
            int sum = 0;
            int cnt = 0;
            for(int i = 0; i<arr.size(); i++) {
                if(1 & (mask >> i)) {
                    sum += arr[i];
                    cnt++;
                }
            }
            arr_pre[cnt].push_back(sum);
        }
        for(int mask = 1; mask < (1 << (int)brr.size()); mask++) {
            int sum = 0;
            int cnt = 0;
            for(int i = 0; i<brr.size(); i++) {
                if(1 & (mask >> i)) {
                    sum += brr[i];
                    cnt++;
                }
            }
            brr_pre[cnt].push_back(sum);
        }
        
        for(int i = 0; i<30; i++)
            sort(brr_pre[i].begin(), brr_pre[i].end());

        int ans = abs(arr_pre[n/2][0] - brr_pre[n/2][0]);
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total / 2;

        for(int i = 1; i<30; i++) {
            if(arr_pre.empty()) continue;
            int req = n/2 - i;

            if(req < 0) continue;
            if(brr_pre[req].empty()) continue;

            for(int &a: arr_pre[i]) {

                auto ub = upper_bound(brr_pre[req].begin(), brr_pre[req].end(), target - a);
                auto lb = ub == brr_pre[req].begin() ? ub : prev(ub);

                ub = ub == brr_pre[req].end() ? prev(ub): ub;

                int part1 = a + *ub, remain1 = total - part1;
                int part2 = a + *lb, remain2 = total - part2;

                ans = min(ans, abs(remain1 - part1));
                ans = min(ans, abs(remain2 - part2));

            }

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