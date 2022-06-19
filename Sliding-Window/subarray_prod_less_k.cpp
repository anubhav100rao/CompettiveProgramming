#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        int i = 0, j = 0;
        int cnt = 0;
        int prod = 1;
        int n = nums.size();
        for(j = 0; j < n; j++) {
            prod *= nums[j];
            while(prod > k) {
                prod /= nums[i++];
            }
            cnt += j - i + 1;
        }      
        return cnt;
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