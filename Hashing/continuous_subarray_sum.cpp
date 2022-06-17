#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    /**
     * THIS PROBLEM IS SAME AS FINDING A SUBARRAY WHOSE SUM IS 0
     * 
     * 
     * we need to state true or false
     * if there exist a subarray len(i, j) > 1
     * such sum(subarray(i, j)) % k = 0
     * 
     * approach we maintain a runningSum % k and put it inside a set
     * if current runningSum is found in the set then we return true
     * else return false
    */
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1) return false;
        
        map<int, int>hsh = {{0, -1}};
        
        long long runningSum = 0;
        
        for(int i = 0; i<nums.size(); i++) {
            runningSum += nums[i];
            runningSum %= k;
            if(hsh.count(runningSum)) {
                if((i - hsh[runningSum]) > 1) return true;
            }
            else hsh[runningSum] = i;
        }

        return false;
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