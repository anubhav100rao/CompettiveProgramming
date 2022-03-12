#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution
{
    public:
    vector<int> subarraySum(int arr[], int n, long long s) {       
        vector<long long>pre(n+1, 0LL);
        for(int i = 1; i<=n; i++) {
            pre[i] = pre[i-1] + arr[i-1];
        }
        
        int left = 0, right = 0;
        
        while(right <= n) {
            if(pre[right] - pre[left] < s) right++;
            else if(pre[right] - pre[left] > s) left++;
            else return {left+1, right};
        }
        return {-1};
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