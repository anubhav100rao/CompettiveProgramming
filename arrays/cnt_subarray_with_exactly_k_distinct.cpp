#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    int solve_exactly_k(vector<int>&nums, int k) {
        if(k == 0) return 0;
        map<int, int>seen;
        int cnt = 0;
        map<int, int>hsh_idx;
        int start = -1;
        for(int i = 0; i<nums.size(); i++) {
            if(seen.size() == k and !seen.count(nums[i])) {
                auto [a, b] = *hsh_idx.begin();
                hsh_idx.erase(hsh_idx.begin()); seen.erase(b);
                start = a;
            }
            if(seen.count(nums[i])) {
                hsh_idx.erase(seen[nums[i]]);
            }
            seen[nums[i]] = i;
            hsh_idx[i] = nums[i];
            cnt += i - start;
        }
        
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve_exactly_k(nums, k) - solve_exactly_k(nums, k - 1);
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