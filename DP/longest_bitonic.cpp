#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution{
	public:
    vector<int> lis(vector<int>&arr) {
        int n = arr.size(), inf = 1e9 + 7;
        vector<int>p(n, 1);
        vector<int>dp(n+1, inf);
        int ans = 1;
        dp[0] = -inf;
        for(int i = 0; i<n; i++) {
            int j = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            if(arr[i] > dp[j-1] and arr[i] < dp[j]) {
                dp[j] = arr[i];
                ans = max(ans, j);
            }
            p[i] = ans;
        }
        return p;
    }
    


	int LongestBitonicSequence(vector<int>nums) {
        vector<int>A = lis(nums);
        reverse(nums.begin(), nums.end());
        vector<int>B = lis(nums);
        reverse(B.begin(), B.end());

        int n = nums.size();

        int ans = 1;
        for(int i = 0; i<n; i++) {
            ans = max(ans, A[i] + B[i] - 1);
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
    int n; cin >> n;
    vector<int>arr(n, 0);
    for(int &i: arr)
        cin >> i;
    Solution sol;
    cout << sol.LongestBitonicSequence(arr) << '\n';
    return 0;
}