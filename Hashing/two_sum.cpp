#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>hsh;
        for(int i = 0; i<nums.size(); i++) {
            if(hsh.count(target - nums[i])) {
                return {hsh[target - nums[i]], i};
            }
            hsh[nums[i]] = i;
        }      
        return {};
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