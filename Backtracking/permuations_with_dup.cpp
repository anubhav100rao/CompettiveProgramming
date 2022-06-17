#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    vector<vector<int>>res;

    void backtrack(vector<int>&temp, vector<bool>&used, vector<int>&nums) {
        if(temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for(int i = 0; i<nums.size(); i++) {
            if(used[i] || i > 0 && nums[i] == nums[i-1] && !used[i - 1]) continue;
            temp.push_back(nums[i]);
            used[i] = true;
            backtrack(temp, used, nums);
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        vector<bool>used(nums.size(), false);
        backtrack(temp, used, nums);
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