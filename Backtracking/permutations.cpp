#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    vector<vector<int>>res;

    void backtrack(vector<int>&temp, set<int>&done, vector<int>&nums, int idx) {
        if(temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for(int i = 0; i<nums.size(); i++) {
            if(done.count(nums[i])) continue;
            temp.push_back(nums[i]);
            done.insert(nums[i]);
            backtrack(temp, done, nums, i + 1);
            done.erase(temp.back());
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        set<int>done;
        backtrack(temp, done, nums, 0);
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