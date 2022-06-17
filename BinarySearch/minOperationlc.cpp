#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    /**
     * find minOperations required to make nums continuous
     * which means max(nums) - min(nums) = len(nums) - 1
     * all elements are unique
     * 
     * max possible answer is n-1
     * idea : sort the array
     * then for each index we are intrested in finding the maximum longest subarray from i
     * where max element is <= i + n - 1, we can find this using binary seach
     * 
     * then continuousLen = upper_bound_result - i
     * ans = min(ans, n - continuousLen)
    */
    int minOperations(vector<int>& nums) {
        set<int>unique;
        for(int i: nums) unique.insert(i);
        int n = nums.size();
        nums.clear();
        for(int i: unique) nums.push_back(i);

        int ans = n - 1;
        for(int i = 0; i<nums.size(); i++) {
            int en = nums[i] + n - 1;
            int idx = upper_bound(nums.begin(), nums.end(), en) - nums.begin();
            int continuousLen = idx - i;
            ans = min(ans, n - continuousLen);
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