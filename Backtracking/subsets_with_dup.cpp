#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    vector<vector<int>>res;

    void backtrack(vector<int>&temp, vector<int>&nums, int idx) {
        res.push_back(temp);
        for(int i = idx; i<nums.size(); i++) {
            if(i > idx and nums[i] == nums[i-1]) {
                continue;
            }
            temp.push_back(nums[i]);
            backtrack(temp, nums, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        backtrack(temp, nums, 0);
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