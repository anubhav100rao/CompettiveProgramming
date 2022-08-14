#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n, k;
    vector<int>nums;
    vector<vector<int>>dp;
    int solve(int idx, int space) {
        if(idx >= n) return 0;
        
        
        
        if(idx == n - 1) {
            if(space >= nums[idx]) return 0;
            return (space + 1) * (space + 1);
        }
        
        if(space == -1) {
            return solve(idx, k);
        }
        
        if(dp[idx][space] != -1)
            return dp[idx][space];
        
        if(space == k) {
            return dp[idx][space] = solve(idx + 1, space - nums[idx] - 1);
        }
        
        if(space >= nums[idx]) {
            return dp[idx][space] = min(solve(idx + 1, space - nums[idx]  - 1), ((space + 1) * (space + 1)) + solve(idx, k));
        }
        return dp[idx][space] = ((space + 1) * (space + 1)) + solve(idx, k);
        
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        this->nums = nums;
        this->n = nums.size();
        this->k = k;
        dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return solve(0, k);
    } 
};



int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}